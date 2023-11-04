#!/bin/bash

RED='\033[1;32m'
NC='\033[0m'

echo -e "${RED}Building Python wheel...${NC}"
cd ..
python3 setup.py bdist_wheel

echo -e "${RED}Installing Python wheel and upgrading packages...${NC}"
./venv/bin/pip install -U ../spg-opengl/dist/display-0.0.1-cp310-cp310-linux_aarch64.whl --force-reinstall

echo -e "${RED}Finished running the script.${NC}"
