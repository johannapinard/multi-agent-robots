# Capability-Aware Collaborative Robots

Repository for Intelligent Robotics MSc project.

<!-- Badges: build | docs | license -->

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Configuration](#configuration)
- [Development](#development)
- [Authors](#authors)

## About

This project explores methods for enabling collaborative robots to be aware of their capabilities (sensing, actuation, planning) and to adapt their behaviour in multi-agent or human-robot teamwork settings. The repo contains code, experiments, and notes related to capability models, task allocation, and safe collaboration.

## Getting Started



### Prerequisites

- Python 3.10+ or compatible environment
- Optional: ROS 2, Docker (for reproducible environments)

### Installation

Clone and prepare the environment:

```bash
git clone https://github.com/yourusername/your-repo.git
cd your-repo
# create virtualenv and install deps (example)
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

## Usage

Examples for running simulations and experiments:

```bash
# run a demo simulation
# python -m src.simulation.demo

# run an experiment script
# python -m experiments.run --config configs/exp1.yaml
```

## Configuration

Document environment variables and config files (e.g., `configs/*.yaml`) used to control experiments, seeds, and resource paths.

## Development

Describe the development workflow, code organization, and how to run tests.

```bash
# run tests
# pytest -q
```

## Authors

- Johanna Pinard
