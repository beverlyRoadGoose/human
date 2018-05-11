#!/usr/bin/env bash

cmake -DCMAKE_PREFIX_PATH=lib/wxWidgets/build-debug/ -DCMAKE_EXPORT_COMPILE_COMMANDS=O -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . && make
