#
# Makefile du projet.
#

# Répertoire d'installation de CMocka.
# TODO :
export CMOCKA = /home/joshua/Documents/Outils_Logiciels/cmocka-x86_64/

#
# Organisation des sources.
#

export SRCDIR = src
export TESTDIR = test
export BINDIR = bin

SUBDIRS = $(SRCDIR) $(TESTDIR)

#
# Définitions des outils.
#

export CC = gcc

export CCFLAGS  = -O0 
export CCFLAGS += -DNDEBUG # avec debuggage : -g -DDEBUG # sans debuggage : -DNDEBUG
export CCFLAGS += -MMD -MP # Gestion automatique des dépendances.
export CCFLAGS += -D_BSD_SOURCE -D_XOPEN_SOURCE_EXTENDED -D_XOPEN_SOURCE -D_DEFAULT_SOURCE -D_GNU_SOURCE
export CCFLAGS += -std=c99 -Wall -pedantic
export CCFLAGS += -Wno-unused-function -Wno-unused-variable
export LDFLAGS  = 

#
# Définitions des binaires à générer.
#

export PROG = $(BINDIR)/pg_exemple
export TEST = $(BINDIR)/pg_exemple_test

#
# Règles du Makefile.
#

# Compilation.
all: 
	@for i in $(SUBDIRS); do (cd $$i && $(MAKE) $@); done

# Nettoyage.
.PHONY: clean

clean:
	@for i in $(SUBDIRS); do (cd $$i && $(MAKE) $@); done
	@rm -f $(PROG) $(TEST) core* $(BINDIR)/core*

