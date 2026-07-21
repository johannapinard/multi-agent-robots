from setuptools import find_packages, setup

package_name = 'multi_agents'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Johanna',
    maintainer_email='johanna.pinard@yahoo.fr',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'RB3_robot_node = multi_agents.robots.RB3:main',
            'XGOLite_robot_node = multi_agents.robots.XGOLite:main',
        ],
    },
)
