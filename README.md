[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Deadly Roll]

## Theme and Setting
*Deadly Roll* is set in a gritty medieval fantasy world. You take on the role of a heroic adventurer facing off against dark creatures and rival warriors by the glow of tavern torches and in the halls of ancient castles.

## Core Mechanics
1. **Dice Rolls**  
   - The player and enemy each roll a six-sided die.  
   - The higher roll grants Attack Points (AP) equal to the die result.

2. **Accumulating and Spending AP**  
   - Unspent AP carries over between turns.  
   - Spend AP to:
     - **Basic Attack**: 1 AP → 5 damage  
     - **Special Skills**: variable AP cost → damage or healing  
     - **Skip Turn**: save AP for future turns

3. **Type Advantages & Disadvantages**  
   - Each character has a type (Fire, Water, Earth, etc.).  
   - Attacking a weak type deals ×2 damage; attacking a strong type deals ×0.5 damage.

4. **Special Items**  
   - Equip one item before battle; items last a set number of turns.  
   - Items grant percentage-based bonuses to damage or dodge.  
   - When an item’s duration hits zero, it **BREAKS** and is removed.

5. **Victory & Progression**  
   - Defeat the enemy by reducing their HP to zero.  
   - Earn random EXP (0–10) on victory to level up and unlock new characters.

## Gameplay Overview
- **Risk vs. Reward**: Decide between powerful attacks now or saving AP for stronger skills.  
- **Inventory Strategy**: Choose the best item to complement your build.  
- **Character Progression**: Level up, create new characters of different types, and combine skills and items.

## Applied Concepts
1. **Variables & Data Types**  
   ```cpp
   int playerHp = 30, enemyHp = 30;
   float damageMultiplier = getTypeMultiplier(...);
   ```
2. **Conditional Structures**  
   ```cpp
   if (playerRoll > enemyRoll) { /* player wins */ }
   else if (enemyRoll > playerRoll) { /* enemy wins */ }
   else { /* tie */ }
   ```
3. **Switch Statements**  
   ```cpp
   switch (menuChoice) {
     case 1: playGame(); break;
     case 2: manageCharacters(); break;
   }
   ```
4. **Loops**  
   - `while (playerHp > 0 && enemyHp > 0)` for the battle loop.  
   - `for (int i = 0; i < skills.size(); ++i)` for listing skills.
5. **Functions & Modularity**  
   - `startGame()`, `showRules()`, `getIntInput()`, etc.  
   - Each subsystem (UserManager, Game, Utils) in its own `.h/.cpp`.
6. **Data Structures**  
   - `vector`, `struct Character`, `struct Skill`, etc.
7. **File I/O**  
   - Loading/saving users, inventories, characters from text files.
8. **Error Handling**  
   - Validating user input ranges; checking file existence.
9. **Console Interface**  
   - Clear menus, prompts, status messages, and feedback.

## Technical Details
- **Language**: C++11 
- **Clone the repositorie in bash**
```
git clone https://github.com/FDP-01-2025/project-fishybunny-exe.git
 cd project-fishybunny-exe/
```
- **Compile the project in console**
```
g++ -std=c++11 -I src src/*.cpp -o deadly_roll
```
- **Execute the game in console**
```
./deadly_roll
```
- **Project Structure**:  
  ```
  project-root/
  ├─ src/
  │   ├─ main.cpp
  │   ├─ Game.cpp/.h
  │   ├─ Menu.cpp/.h
  │   ├─ Utils.cpp/.h
  │   └─ ...
  ├─ README.txt
  └─ data/ (user and save files)
  ```

## Console Mockups

## 1) User Menu

```
=== USER MENU ===
1) Create User
2) Delete User
3) Choose User
4) Exit Program
Choose: _
```

* **Create User** → asks for a name, comes back to this menu.
* **Delete User** → shows user list, ask for who you want to delete, comes back.
* **Choose User** → shows user list, ask for who you choose, logs in.
* **Exit Program** → finishes the program.

---

## 2) Game Menu

When you choose “Bunny”:

```
=== DEADLY ROLL ===
Welcome, Bunny!

--- GAME MENU ---
1) Play Game
2) Manage Characters
3) View Rules
4) Inventory & Level
5) Back to User Menu
Choose: _
```

---

## 3) Play Game

### 3.1) Equip an object (optional)

```
Equip an item before battle? (0 to skip)
1) Rusted Longsword (5 turns remaining)
2) Frostbrand Axe (3 turns remaining)
3) ... 
Choose item #: _
```

### 3.2) Character Selection

```
1) Default Characters (18)
2) Your Characters (2)
3) Back
Choose: 1

Select your character:
  1) Footman (Normal)
  2) Pyromancer (Fire)
  3) ...
Choose: _
```

### 3.3) Enemy Selection (Random)

```
Enemy: Iron Golem (Metal)
```

---

## 4) Battle Screen

Every turn it shows the status and options:

```
[Status] You: 30 HP | Enemy: 30 HP

-- Roll dice (ENTER) --
```

After push ENTER:

```
You rolled: 4    Enemy rolled: 2
You win the roll! AP = 4

HP 30 vs 30 | AP = 4
0) Skip
1) Basic Attack (1 AP, 5 dmg)
2) Ember Strike (5 AP, 10 dmg)
3) Rejuvenate (7 AP, +10 HP)
Choose action: _
```

* If you choose **Basic Attack**, it shows:

  ```
  You hit for 5 damage!
  ```
* If the enemy dodges:

  ```
  Enemy dodged your Basic Attack!
  ```

Then it is enemy turn:

```
Enemy wins roll! Enemy AP = 3
Enemy uses Iron Wall and heals 10 HP!
```

And it is a loop until someone win:

```
*** You Win! ***
You gained 7 EXP.
Rusted Longsword has 4 turns remaining in your inventory.
```

Or:

```
*** You Lose... ***
```

---

## 5) Manage Characters

```
--- CHARACTER MENU ---
1) Create Character
2) Delete Character
3) Back
Choose: _
```

* **Create** → ask you a name, shows you a list of the types, asks you a type for your character, comes back.
* **Delete** → Shows you the created character, asks for who you want to delete, comes back.

---

## 6) View Rules

```
=== GAME RULES ===

Types:
  0) Fire
  1) Water
  ...
 17) Rock

Type Matchups (A > B):
  Fire > Ice, Ice > Water, Water > Fire
  ...

Default Characters:
  Footman (Normal)
  Pyromancer (Fire)
  ...

Special Items (Duration, +% Dmg, +% Dodge):
  Rusted Longsword (20 turns): +10% dmg, +0% dodge
  Frostbrand Axe  (10 turns):  +0% dmg, +15% dodge
  ...

Press ENTER to go back...
```

---

## 7) Inventory & Level

```
Inventory for Bunny:
  1) Rusted Longsword (4 turns remaining)
  2) Frostbrand Axe  (10 turns remaining)
  ...

Level: 3 | EXP: 17 (30 to next level)

Press ENTER to go back...
```

---
### Flow Chart
1. **CharacterManagerCPP**
   ![](CharacterManagercpp.png)
2. **CharacterManagerH**
   ![](charactermanagerh.png)
3.**FileManagerCPP**
   ![](filemanagercpp.png)
4.**FileManagerH**
   ![](filemanagerh.png)
5.**GameCPP**
## Team
**Team Name:** FishyBunny.exe

- Jorge Alejandro Erazo Durán (00047225)  
- Diego Roberto Cruz Novoa (00140725)  
- Carlos Alberto Flores Bonilla (00079225)  
- César Fernando Fuentes Moreno (00118825)
