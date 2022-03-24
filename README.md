Nom du projet: Triland

Membre du projet :

    - Lotfy Ali          / p1806435
    - Saïd Ali Fourkane  / p1802776
    - Tracol Dimitri     / p1806169

Url du git:

    https://forge.univ-lyon1.fr/p1802776/rogue-like-triade
    
    Project ID: 13342

Description brève:

    Triland est un jeu rogue like inspiré de Binding Of Isaac.

But du jeu:

    Traverser les niveau en passant de salle en salle, trouver la salle du Boss de 
    chaque niveau et battre le Boss pour passer au niveau suivant.

    - Des monstres se trouvent dans chaques salles, il faut les battre pour 
      pouvoir accéder aux salles suivantes.

    - Il à une salle d'objet dans chaque niveau permettant au joueur d'acquérir
      un objet qui le rend plus fort.

    Il faut arriver en vie à la fin du troisième niveau pour finir le jeu.

Compilation:

    Utiliser la commande "make" dans un terminal ouvert dans le dossier "rogue-like-triade".

Execution:

    Utiliser la commande "bin/app" dans un terminal ouvert dans le dossier "rogue-like-triade".

Utilisation:

    - Choisir un personnage lorsque l'écran de démarrage s'affiche en appuyant 
      sur "T", "E" ou "D" selon le personnage désiré.

    - Pour déplacer le personnage il faut utiliser les touches "Z","Q","S" et "D".

    - Pour tirer un projectile il faut utiliser les flèches directionnelles
      Le personnage tirera dans la direction de la flèche.

    - Il suffit de marcher sur les objets pour les ramasser.

    - Il faut tirer des projectiles sur les monstre pour leurs infligés des dégâts.

Fonctionnalités:

    - Il est possible de choisir quel type de personnage on veut jouer pendant que
      l'écran de démarrage est affiché.

    - Le niveau est généré aléatoirement c'est à dire que la disposition des salles 
      est différente à chaque fois qu'on lance le jeu.

    - Les salles sont égalements générées aléatoirements, les obstacles,
      la disposition des monstre, le nombre de monstre sont différents dans
      chaque salles.

    - Le personnage peut se déplacer librement mais ne peut pas traverser les obstacles.

    - Le personnage tire des projectiles dans la direction voulu, ces projectiles sont 
      les attaques du joueur.

    - Le joueur possède un mini-map lui permettant de savoir dans quelle salle
      il se trouve et quelles salles il à déjà visitées.

    - Le personnage possède une barre de vie qui est dimmensionée en fonction
      du nombre de points de vie maximum du personnage et change de couleur en 
      fonction des points de vie actuels du personnage.

    - Un compteur de niveau affiche le niveau actuel.

    - Le personnage peut changer de salle en traversant les portes situées au milieu 
      des cotés de la salle.

    - Quand un joueur arrive dans une salle il est invincible pendant un court instant
      pour éviter qu'il prenne des dégats car un monstre se trouvais juste derrière la porte.

    - Les portes de la salle sont fermées tant que tous les monstres de la salle 
      ne sont pas morts.

    - Les monstres se déplacent dans la direction du personnage, si un monstre 
      touche un joueur, le joueur perd des points de vie.
      Si le monstre est touché par un projectile du joueur alors le monstre
      perd de la vie.

    - Si le personnage est touché alors il sera invincible pedant un court
      instant lui permettant de s'échapper.

    - Le personnage peut récupérer des objets dans les salles d'objets.
      si le joueur récupère un objet alors il gagnera les statistiques de l'objet.
      Les objets sont générés aléatoirements.

    - Le personnage doit affronter un boss à chaque niveau, Le Boss est plus fort que
      les monstres normaux.

    - Il y a des pièges dans la salle du Boss, si le personnage marche dessus
      il perd des points de vie.

    - Si le joueur bat le monstre alors il passe au niveau suivant.

    - Si le joueur perd tout ces points de vie alors il meurt et un écran
      de mort est affiché.

    - Si le joueur bat le boss du troisième étage alors il gagne et un écran de victoire s'affiche.

    - Il est possible de quitter pendant le jeu en fermant la fenêtre de jeu.


Organisation de l'archive :

    - Tous les dossiers se trouvent dans le dossier "rogue-like-triade"
      avec le Makefile et le ReadMe.

        - Dans le dossier "bin" se trouve l'application "app".

        - Dans le dossier "data" comporte deux sous dossier :

            - "images" ou se trouve les images.

            - "polices" ou se trouve les polices.

        - Dans le dossier "doc" se trouve la doxygen.

        - Dans le dossier "obj" comporte les fichiers objets ".o" du projet.

        - Dans le dossier "src" on trouve les fichiers ".cpp" et ".h" du projet.
