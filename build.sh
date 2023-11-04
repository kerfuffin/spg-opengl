#!/bin/bash

RED='\033[1;31m'
NC='\033[0m'

echo -e "${RED}Running cmake...${NC}"
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -G Ninja -S . -B cmake-build-debug

echo -e "${RED}Building Python wheel...${NC}"
python3 setup.py bdist_wheel

echo -e "${RED}Installing Python wheel and upgrading packages...${NC}"
cd ../python-test/
./.venv/bin/pip install -U ../spg-opengl/dist/display-0.0.1-cp310-cp310-linux_aarch64.whl --force-reinstall

echo -e "${RED}Finished running the script.${NC}"
