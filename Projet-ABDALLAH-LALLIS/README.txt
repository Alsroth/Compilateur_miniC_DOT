Pour pouvoir tester ce projet il est necessaire d'avoir lex et yacc d'installer sur votre machine.
De plus ce projet à été prévu pour fonctionner sur linux et mac.

Il contient un compilateur qui transforme un programme miniC en un programme DOT réalisé en groupe de 2. 

Pour lancer le compilateur, vous pouvez exécuter ces commandes ci-dessous dans un terminal en vous plaçant dans le dossier Projet-ABDALLAH-LALLIS :

-       sudo chmod +x lexYacc.txt
-	./lexYacc.txt miniC

Ensuite pour tester le compilateur avec le fichier Tests/nomdutest.c, exécutez cette commande :

-	./compiler < Tests/nomdutest.c nomdesortie

Le fichier de destination se trouve dans DOT/nomdesortie.dot .

Par exemple, pour tester le fichier Tests/add.c, la commande à executer sera :

-	./compiler < Tests/add.c add

un fichier add.dot est créé dans le dossier de destination DOT .
