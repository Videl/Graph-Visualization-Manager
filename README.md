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
    depot4 0

Il faut bien noter la taille minimale du **nombre** dans les distances, c'est-à-dire 3 chiffres. Pour le modifier, c'est la variable pré-processeur #define SIZE_NUMBER.

Exemple
=======

    videl@lucille:/.../% ./general 
    ###############################################
    #                   Projet C                  #
    #    Visualisation d'un réseau de transport   #
    ###############################################
    Comment voulez-vous utiliser ce programme ?
    1. Utiliser un réseau deja existant
    2. Créer son propre reseau
    % 1
    ###################################
    # Création de dépôt déjà existant #
    ###################################
    Indiquez le nom du fichier texte contenant les informations : graphe.txt
    Nombre de dépôts : 7
    Format d'affichage : (index dépôt, distance)
    *** Note : index dépôt commence à zéro ! ***
    Successeurs du dépot "depot0" : (4, 232) (0, 434) (6, 159) 
    Successeurs du dépot "depot1" : (4, 358) 
    Successeurs du dépot "depot2" : (5, 422) (0, 348) 
    Successeurs du dépot "depot3" : (2, 209) (1, 340) (3, 333) (4, 359) (5, 447) 
    Successeurs du dépot "depot4" : (3, 424) (6, 156) (5, 176) (5, 234) 
    Successeurs du dépot "depot5" : (0, 456) (5, 416) (2, 304) (3, 371) 
    Successeurs du dépot "depot6" : (6, 453) (5, 120) (2, 588) (1, 460) (1, 135)
    Quel est le dépôt de départ ? depot0
    Quel est le dépôt d'arrivée ? depot1
    Trajet : 
    depot1(783) <-(135)- depot5(648) <-(416)- depot4(232) <-(232)- depot0
    Indiquez le nom du fichier texte contenant les informations :
    (Le lien complet à partir de la racine du projet) : reseau/graphe.txt
    Indiquer le nom du fichier .dot en sortie : test51.dot
    ./dot_maker/text_to_dot reseau/graphe.txt test51.dot... exécuté.
    Indiquer le nom du fichier image (.png) en sortie : image51.png
    dot -T png -o image51.png test51.dot... exécuté.
    videl@Lucille:/.../% feh test51.png
Auteurs
=======
 * Signoret Manon
 * Smith Thibaut
