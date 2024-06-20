#!/bin/bash

# Download and extract the BSP package
wget -O- http://mscc-ent-open-source.s3-eu-west-1.amazonaws.com/public_root/bsp/mscc-brsdk-arm64-2024.03.tar.gz | tar -xz -C .

# Download and extract the toolchain package
wget -O- http://mscc-ent-open-source.s3-eu-west-1.amazonaws.com/public_root/toolchain/mscc-toolchain-bin-2023.02-101.tar.gz | tar -xz -C .
