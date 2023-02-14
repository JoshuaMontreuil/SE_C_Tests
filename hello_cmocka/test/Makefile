#
# Makefile des tests du projet.
#

#
# Organisation des sources.
#

# Packages.
PACKAGES = pkg 

# Wrap des méthodes pour bouchonnage.
LDWRAP  = -Wl,--wrap=mod2_fct1 -Wl,--wrap=mod2_fct2 -Wl,--wrap=mod1_fct4
LDWRAP  += -Wl,--wrap=mod1_fct_st1

# Méthodes bonchounées pour des besoins internes à un module.
CCFLAGS += -D_WRAP_MOD1_FCT4 
CCFLAGS += -D_WRAP_MOD1_FCT_ST1
CCFLAGS += -D_MOCK_PERSO_MOD1_FCT_ST1

# Un niveau de package est accessible.
SRC = $(wildcard */*.c)		
OBJ = $(SRC:.c=.o)

# Point d'entrée du programme.
MAIN = main_test.c

# Gestion automatique des dépendances.
DEP = $(MAIN:.c=.d)

# Executable à générer
EXEC = ../$(TEST)

# Inclusion depuis le niveau du package.
CCFLAGS += -I. -I$(CMOCKA)/include

# Liens pour les tests.
LDFLAGS += -L$(CMOCKA)/lib

# Utilisation de la librairie static CMocka
LDFLAGS += -lcmocka-static

#
# Règles du Makefile.
#

# Compilation.
all: 
	@for p in $(PACKAGES); do (cd $$p && $(MAKE) $@); done
	@$(MAKE) $(EXEC)

$(EXEC): $(OBJ) $(MAIN)
	$(CC) $(CCFLAGS) $(LDWRAP) $(OBJ) $(MAIN) -MF $(DEP) -o $(EXEC) $(LDFLAGS)

# Nettoyage.
.PHONY: clean

clean:
	@for p in $(PACKAGES); do (cd $$p && $(MAKE) $@); done
	@rm -f $(DEP)

-include $(DEP)

