Graph-Visualization-Manager
===========================

Le but de ce sujet est de simuler un réseau de transport de marchandises. Pour simpliﬁer, on considère une seule marchandise. On dispose d’un certain nombre de dépôts reliés entre eux par des liaisons qui permettent le transport de la marchandise en question. Chaque paire de dépôts ne dispose pas forcément d’une liaison directe. Le programme à réaliser doit permettre à un utilisateur de :

 * déﬁnir son réseau (le nombre de dépôts, leurs localisation, les liaisons existantes, . . .). On doit être en mesure de déﬁnir la topologie manuellement ou de la générer aléatoirement : on spéciﬁe le nombre de dépôts et on génère aléatoirement leurs positions, le dépôt source, le (les) dépôt(s) destinataire(s), le coût éventuel d’une liaison (cf plus bas),
 * visualiser le réseau. Il est imposé d’utiliser graphviz http://www.graphviz.org/, un logiciel libre de visualisation de graphes.
 * trouver un chemin qui permet le transport de la marchandise d’un dépôt à un autre avec visualisation graphique de ce chemin.


How-to
======

Fichier texte descriptif d'un réseau
------------------------------------
Le fichier texte d'un réseau se compose de ces éléments :

    nb
    nom_dépôt_a nombre_de_connections numéro_du_dépôt_b distance_dépôt_a_>_b [liaisons autres dépôts]
    [ autre ligne correspondant à un dépôt et à ces connections ]
  
``nb`` correspond au nombre de dépôts qui seront explicités dans la suite du fichier.
Exemple avec quatre dépôts :

    4
    depot1 3 2 023 3 046 4 067
    depot2 2 3 045 4 046
    depot3 1 4 027
    depot4 3

Il faut bien noter la taille minimale du **nombre** dans les distances, c'est-à-dire 3 chiffres. Pour le modifier, c'est la variable pré-processeur #define SIZE_NUMBER.
