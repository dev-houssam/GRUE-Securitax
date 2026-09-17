# GRUE Securitax

### Système de levage sécurisé basé sur LEGO Mindstorms EV3

**GRUE Securitax** est un projet de robotique développé autour d'une brique **LEGO Mindstorms EV3**. Le système permet de piloter une grue équipée d'un moteur et de capteurs de contact, avec un mécanisme de sécurité destiné à limiter certains mouvements de la charge.

Le programme propose deux modes de fonctionnement : **manuel** et **enregistrement**. Un code secret doit être saisi à l'aide des boutons de la brique EV3 avant d'accéder au système.

---

## 🚧 Fonctionnalités

### 🔐 Démarrage sécurisé

La grue ne démarre qu'après saisie d'un code à l'aide des boutons de la brique EV3.

La combinaison utilisée pour démarrer le système est :

```text
HAUT + DROITE
```

Une fois le code validé, le menu principal est affiché.

---

## 🎮 Mode manuel

Le mode manuel permet de contrôler directement le mouvement de la grue à l'aide des capteurs de contact.

```text
HAUT + BAS
        ↓
   Mode Manuel
```

Les capteurs permettent de commander les mouvements de montée et de descente.

Chaque mouvement est accompagné d'un **signal sonore**, permettant notamment d'indiquer l'action en cours.

Le mode peut être quitté en appuyant sur :

```text
GAUCHE
```

---

## 🛡️ Système de sécurité

Le programme utilise l'**encodeur du moteur** pour suivre la position angulaire du mécanisme.

Lorsqu'une montée est demandée, l'angle du moteur est contrôlé afin d'empêcher la grue de poursuivre son mouvement lorsque la limite définie par le programme est atteinte.

La logique de sécurité repose notamment sur une plage d'angle :

```text
-30° < angle ≤ 50°
```

Cette vérification permet de déterminer si le mouvement de montée doit être autorisé.

---

## 💾 Mode enregistrement

Un second mode est prévu pour permettre l'enregistrement de positions de la grue.

L'objectif est de pouvoir enregistrer jusqu'à **quatre positions** puis commander ultérieurement la grue afin d'atteindre ces positions.

Les commandes prévues sont :

| Bouton | Position   |
| ------ | ---------- |
| GAUCHE | Position 1 |
| BAS    | Position 2 |
| DROITE | Position 3 |
| HAUT   | Position 4 |

La documentation du projet indique cependant que le **mode enregistrement n'était pas fonctionnel dans cette version**. Le code contient néanmoins la structure du mode et les mécanismes de commande de base.

---

## ⚙️ Architecture du système

Le système repose sur une brique **LEGO Mindstorms EV3** connectée à différents composants :

```text
              ┌─────────────────────┐
              │     Brique EV3      │
              │                     │
              │  Boutons de contrôle│
              └──────────┬──────────┘
                         │
                         ▼
                ┌─────────────────┐
                │ Programme EV3   │
                └────────┬────────┘
                         │
              ┌──────────┴──────────┐
              ▼                     ▼
       ┌─────────────┐       ┌─────────────┐
       │ Capteurs    │       │   Moteur A  │
       │ de contact  │       │             │
       │ S2 / S4     │       │  Mouvement  │
       └─────────────┘       └─────────────┘
```

Le programme configure notamment les capteurs **S2** et **S4** comme capteurs de contact et utilise le moteur **A** pour commander le mécanisme de la grue.

---

## 🔊 Retour sonore

Les déplacements de la grue sont accompagnés de signaux sonores.

Deux tonalités sont notamment utilisées pour distinguer les mouvements :

```text
450 Hz → mouvement de descente
650 Hz → mouvement de montée
```

Le programme utilise également des tonalités lors du démarrage du système.

---

## 🧠 Logique du programme

Le programme repose sur une gestion par **modes d'exécution** :

```text
                Démarrage
                    │
                    ▼
             Code secret
                    │
                    ▼
               Menu principal
                    │
          ┌─────────┴─────────┐
          │                   │
          ▼                   ▼
     Mode manuel       Mode enregistrement
          │                   │
          ▼                   ▼
    Contrôle moteur      Positions prévues
          │
          ▼
   Contrôle sécurité
          │
          ▼
       Arrêt
```

Une variable `mode` permet de gérer l'état courant du système :

```text
0 → Menu
1 → Mode manuel
2 → Mode enregistrement
```

---

## 🔧 Technologies et composants

* **LEGO Mindstorms EV3**
* **EV3 sensors**
* **Capteurs de contact**
* **Moteur EV3**
* **Encodeur moteur**
* **Programmation EV3**
* Gestion des entrées utilisateur
* Gestion des états / modes
* Contrôle moteur
* Gestion de la sécurité
* Retour sonore

---

## 🎯 Objectifs du projet

Le projet avait notamment pour objectifs de mettre en œuvre :

* La programmation d'un système robotique
* Le contrôle d'un moteur
* L'utilisation de capteurs
* La lecture des entrées de la brique EV3
* La gestion de plusieurs modes de fonctionnement
* Le suivi de la position d'un moteur
* La mise en place d'une logique de sécurité
* La communication avec l'utilisateur par affichage et signal sonore

---

## 👥 Auteurs

**D. MAROUA & BACAR HOUSSAM**

**Date de création :** Mars 2021
**Version :** V2

---

## 📌 État du projet

La **commande manuelle** et le mécanisme de sécurité associé sont implémentés dans la version fournie.

Le **mode enregistrement** est présent dans la conception du programme, mais est indiqué comme **non fonctionnel** dans la documentation du projet.
