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
- **Compilation**:  
```
  g++ -std=c++11 -I src src/*.cpp -o deadly_roll
  ```
- **Execution**:
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

### User Menu
```
=== USER MENU ===
1) Create User
2) Delete User
3) Choose User
4) Exit Program
Choose: _
```

### Game Menu
```
=== DEADLY ROLL ===
Welcome, <Username>!

--- GAME MENU ---
1) Play Game
2) Manage Characters
3) View Rules
4) Inventory & Level
5) Back to User Menu
Choose: _
```

### Battle Turn
```
[Status] You: 30 HP | Enemy: 30 HP

-- Roll dice (ENTER) --
You rolled: 4    Enemy rolled: 2
You win the roll! AP = 4

0) Skip
1) Basic Attack (1 AP, 5 dmg)
2) Ember Strike (5 AP, 10 dmg)
3) Rejuvenate (7 AP, +10 HP)
Choose: _
```

## Team
**Team Name:** FishyBunny.exe

- Jorge Alejandro Erazo Durán (00047225)  
- Diego Roberto Cruz Novoa (00140725)  
- Carlos Alberto Flores Bonilla (00079225)  
- César Fernando Fuentes Moreno (00118825)
