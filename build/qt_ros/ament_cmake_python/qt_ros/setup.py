from setuptools import find_packages
from setuptools import setup

setup(
    name='qt_ros',
    version='0.0.0',
    packages=find_packages(
        include=('qt_ros', 'qt_ros.*')),
)
