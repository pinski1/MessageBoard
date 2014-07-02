#!/bin/bash

TEMP = wget -q http://www.bbc.co.uk/weather/2653941 -O - | tr '\n' ' ' | grep -o '<span data-unit="c" class="units-value temperature-value temperature-value-unit-c">18<span class="unit">°C</span></span>"(\d+)"<span class="unit">°C</span>'

SKY = wget -q http://www.bbc.co.uk/weather/2653941 -O - | tr '\n' ' ' | grep -o '<span data-unit="c" class="units-value temperature-value temperature-value-unit-c">18<span class="unit">°C</span></span>"(\d+)"<span class="unit">°C</span>'