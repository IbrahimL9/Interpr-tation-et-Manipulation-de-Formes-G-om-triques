1.les Instructions simples:

le teste fourni dans le sujet fonctionne ,nous avons écris une fonction d'affichage qui permet de verifier cela ,tout fonctionne
le fichier forme.hh regoupe la classe mére forme qui est abstraite ainsi que toute les sous classes carré , rectangle... avec chacune ses attribus
et dans notre parser nous avons bien veillé à ce que chaque instructions se finissent bien par un point virgule aussi nous avons fait en sorte que les mots clés ne soit pas sensibles à la casse


2.Les attributs:

le teste fourni dans le sujet fonctionne ,nous avons écris une fonction d'affichage qui permet de verifier cela ,tout fonctionne
nous avons bien distinguer dans la grammaire les deux cas de figures entre les attribus à la suite d'accolade "liste_acc" et ceux à la suite d'une fléche "liste_fleche", aussi pour le cas des accolades nous avons fait en osrte qu'il n'y est pas besoin de point virgule pour finir l'instruction contrairmeent aux autres instruction , l'ajout d'attribus se fait dans la grammaire: figure_att

3.Utilisation des variables:

le teste fourni dans le sujet fonctionne ,nous avons écris une fonction d'affichage qui permet de verifier cela ,tout fonctionne
pour pouvoir stocker les variables avec et sans affectation nous avons crée le fichier "variable_att.hh" on y stocke dans la classe "variable_att" les variables dans un std::map<std::string, std::shared_ptr<Forme>>,
aussi la classe "VariableSansAffectation" stocke un std::vector<std::shared_ptr<Forme>> pour les variable sans affectation et dans le cas d'une création d'une variable avec affectation elle sera stocké dans la premiére classe avec pour clé sans nom et aussi dans la deuxiemme classe pour qu'on puisse y acceder à partir de son indice de création,pour se faire on a fait une methode acces pour les deux classe qui parcours la structure et retourne un pointeur sur la figure trouvé
enfin  VariableType qui est un std::variant peret de stocker les types entiers , booleen et reel
la grammaire "variable" regroupe les création de variable de toutes sorte ainsi que ses modifications

4.Conditionnelles et boucles:

4.1.les conditions :
le teste fourni dans le sujet fonctionne ,nous avons écris une fonction d'affichage qui permet de verifier cela ,tout fonctionne
les fichier expressionsTernaire gére la condition , la comparaison est faites par la grammaire comparaison et retourne un booleen qui reprensente l'évaluation du predicat comparaison grace aux deux fonction evaluation et evauationcouleur , nous avons aussi bien fait en sorte qu'il puissent y avoir des et/ou logique entre les condition 
pour l'operation a faire apres la condition nous avons deux fichiers "expressionmodif" qui gere les modification à partir des attribus et le deuxieme fichier "expressioncritere" qui gére les modif des critére du style positionX , positionY et taille pour les carré d'ailleurs la fonction qui modifie les critére est un peu longue car nous avons tenu à verifier et gerer les erreur comme demander la modifier la taille d'un rectangle sachant qu'il n'est pas sensé en avoir 

4.2.les boucles:
nous avons malheureusement pas eut le temp de le faire

5.Interprétation SVG:
La génération de SVG est réalisée en parcourant le vecteur qui stocke toutes les formes et en convertissant chaque objet en éléments SVG correspondants, en tenant compte de tous les attributs appliqués en utilisant la fonction style.
Ce processus est géré dans le main où un fichier SVG est créé. Les tests fournis dans le sujet fonctionnent.


Dans le sujet, deux incohérences ont été relevées. Premièrement, il existe une ambiguïté entre la longueur et la largeur. Par conséquent, lors des tests, il conviendra d'utiliser "largeur". La deuxième incohérence  concerne l'emplacement du cercle par rapport aux coordonnées fournies au sujet.