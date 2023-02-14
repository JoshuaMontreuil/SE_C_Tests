#
# Makefile des sources du projet.
#

#
# Organisation des sources.
#

# Packages.
PACKAGES = pkg 

# Un niveau de package est accessible.
SRC = $(wildcard */*.c)		
OBJ = $(SRC:.c=.o)

# Point d'entrée du programme.
MAIN = main.c

# Gestion automatique des dépendances.
DEP = $(MAIN:.c=.d)

# Executable à générer
EXEC = ../$(PROG)

# Inclusion depuis le niveau du package.
CCFLAGS += -I.

#
# Règles du Makefile.
#

# Compilation.
all:
	@for p in $(PACKAGES); do (cd $$p && $(MAKE) $@); done
	@$(MAKE) $(EXEC)

$(EXEC): $(OBJ) $(MAIN)
	$(CC) $(CCFLAGS) $(OBJ) $(MAIN) -MF $(DEP) -o $(EXEC) $(LDFLAGS)

# Nettoyage.
.PHONY: clean

clean:
	@for p in $(PACKAGES); do (cd $$p && $(MAKE) $@); done
	@rm -f $(DEP)

-include $(DEP)

