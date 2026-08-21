from __future__ import annotations 

import argparse
from isaaclab.app import AppLauncher

parser = argparse.ArgumentParser(description="Collision Avoidance Environment")
AppLauncher.add_app_launcher_args(parser)
args_cli = parser.parse_args()

app_launcher = AppLauncher(args_cli)
simulation_app = app_launcher.app

import gymnasium as gym
from collision_env import CollisionAvoidanceEnv, CollisionEnvRB3Cfg
import time
import torch
from isaaclab.utils import video


gym.register(
    id="CollisionAvoidance",
    entry_point="collision_env:CollisionAvoidanceEnv",
)

rb3_cfg = CollisionEnvRB3Cfg()

env_cfg = CollisionAvoidanceEnv(cfg=rb3_cfg)

env_cfg.viewer.resolution = (640, 480)
env_cfg.viewer.eye = (1.0, 1.0, 1.0)
env_cfg.viewer.lookat = (0.0, 0.0, 0.0)

env = gym.make(
    "CollisionAvoidance",
    cfg=env_cfg,
    render_mode="rgb_array",
)

video_kwargs = {
    "video_folder": "videos/train",
    "step_trigger": lambda step: True, #step % 1500 == 0,
    "video_length": 100,
}
env = gym.wrappers.RecordVideo(env, **video_kwargs)

    # adjust camera resolution and pose
    # env_cfg.viewer.resolution = (640, 480)
    # env_cfg.viewer.eye = (1.0, 1.0, 1.0)
    # env_cfg.viewer.lookat = (0.0, 0.0, 0.0)
    # # create isaac-env instance
    # # set render mode to rgb_array to obtain images on render calls
    # env = gym.make("RB3 Collision Avoidance", cfg=env_cfg, render_mode="rgb_array")
    # # wrap for video recording
    # video_kwargs = {
    #     "video_folder": "videos/train",
    #     "step_trigger": lambda step: True, # step % 1500 == 0,
    #     "video_length": 100,
    # }
    # env = gym.wrappers.RecordVideo(env, **video_kwargs)


if __name__ == "__main__":
    print("Creating environment...")

    obs, info = env.reset()
    print("AFTER RESET")

    steps = 100

    start_time = time.perf_counter()

    print("training...")
    steps_done = 0
    for step in range(steps):
        actions = torch.zeros(
            (
                env.num_envs,  
                env.cfg.action_space,
            ),
            device=env.device,
        )

        obs, reward, terminated, truncated, info = env.step(actions)

        if terminated or truncated:
            obs, info = env.reset()

    elapsed = (time.perf_counter() - start_time)

    simulated_seconds = (steps * env.cfg.decimation * env.cfg.sim.dt)

    print()
    print("========== BENCHMARK ==========")
    print(f"Environments:       {env.num_envs}")
    print(f"Steps:              {steps}")
    print(f"Steps executed      {steps_done}")
    print(f"Simulated time:     {simulated_seconds:.2f} s")
    print(f"Real time:    {elapsed:.2f} s")
    print(f"Steps/sec:          {steps / elapsed:.2f}")
    print(
        f"Simulation speed:   "
        f"{simulated_seconds / elapsed:.2f}x real-time"
    )
    print("================================")
    env.close()
