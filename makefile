# ----------------------------
# Makefile Options
# ----------------------------

NAME = QuizWhiz
ICON = QuizWhizLogo.png
DESCRIPTION = "Flashcards Quizes"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
