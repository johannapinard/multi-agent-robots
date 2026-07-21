import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/johanna/Workspaces/msc_project_ws/multi-agent-robots/multi_agents_ws/src/install/multi_agents'
