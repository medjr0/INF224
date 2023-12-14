# INF224
[Java][C++] Implementation of client server coding of a remote control app using


Mohamed JARMOUNI
Le partie C++ a été réalisé jusqu’à l’étape 11 (client serveur) puis j’ai réalisé toute la partie
Java Swing.
Pour la partie C++ : le code a été écrit en respectant les principes et les standards de
l’orienté objet. À titre d’exemple :
*le principe d’encapsulation a bien été respecté
*Il y a bien un polymorphisme d’heritage
*La fonction jouer() commune à tout les types de média (photo, video, film ..) à été
implementé comme une fonction ‘virtual’ dans la classe “Multimedia” qui sera ensuité
herité par les classes filles.
Pour bien geré la mémoire dans cette partie, j’ai opté pour l’utilisation des shared pointer
qui font que les objets qui ne sont plus pointé par aucun pointeur seront automatiquement
détruit.
Le code a été tester plusieurs fois (la partie commenté du code de main.cpp) dans la fonction
main avant d’établir la connexion client serveur.
Pour la connexion client-serveur. J’ai défini 3 commandes qui peuvent être reçu par le
serveur et qui sont :

![image](https://github.com/medjr0/INF224/assets/127483073/856baa54-8841-46b3-81bd-b6b862afb2d2)

J’ai bien testé ces commandes avec le client.cpp avant de passer à l’interface graphique.
Pour la partie Java Swing, j’ai opté pour un design simpliste de la fenetre Jframe. En
mettant 2 fonctionnalité (chercher et jouer) sous forme de boutton. Ainsi, en ajouttant une
textArea en haut qui servira comme barre de recherche. Et un deuxieme grosse testArea en
bas qui sert de console pour la télécommande.
Ainsi on peut chercher et jouer de manière intuitive et naturelle en utilisant l’interface
graphique qui a été connecté correctement au serveur c++.
La base de donnée du serveur a été rempli avec les multimedia suivant afin d’effectuer les
tests finaux :

![image](https://github.com/medjr0/INF224/assets/127483073/4568eacf-eb05-4c6e-85ee-da350280c08b)
