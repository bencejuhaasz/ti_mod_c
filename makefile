# ----------------------------
# Makefile Options
# ----------------------------

NAME = MOD
ICON = icon.png
DESCRIPTION = "MOD Calculator for large nums"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
