MODULES = learning Reseau userinfo

all:
    for dir in $(MODULES); do
        (cd $$dir; ${MAKE} all);
        done