### This mod was last updated:
### last version: 01 Dec 2019, TrinityCore revision: [e0835b4673](https://github.com/TrinityCore/TrinityCore/commit/e0835b4673)
### 2013 version: 12 Dec 2013. TrinityCore revision: [385e2dba37](https://github.com/TrinityCore/TrinityCore/commit/385e2dba37)

# [ THE NPCBOTS MANUAL ]
>Compiled by: Trickerer (onlysuffering @ Gmail dot Com)  
>Version 0.7 - 04 Nov 2019  
>Original version by: Thesawolf (@ Gmail dot Com) Version 0.3 - 20 July 2016 [here](https://github.com/thesawolf/TrinityCore/blob/TrinityCoreLegacy/README_Bots.md)

---------------------------------------
### Contents
1. [Introduction](#markdown-header-introduction)
2. [NPCBots](#markdown-header-npcbots)
    - [NPCBot Mod Installation](#markdown-header-npcbot-install)
    - [NPCBot Commands](#markdown-header-npcbot-commands)
    - [NPCBot Control and Usage](#markdown-header-npcbot-control-and-usage)
        - [NPCBot Getting Started](#markdown-header-npcbot-getting-started)
        - [NPCBot Getting Around](#markdown-header-npcbot-getting-around)
        - [NPCBot Equipment](#markdown-header-npcbot-equipment)
        - [NPCBot Roles](#markdown-header-npcbot-roles)
        - [NPCBot Formation](#markdown-header-npcbot-formation)
        - [NPCBot Abilities](#markdown-header-npcbot-abilities)
        - [NPCBot Grouping](#markdown-header-npcbot-grouping)
        - [NPCBot Extras](#markdown-header-npcbot-extras)
    - [NPCBot Config Settings](#markdown-header-npcbot-config-settings)
    - [NPCBot Extra Classes](#markdown-header-npcbot-extra-classes)
    - [NPCBot Occupations](#markdown-header-npcbot-occupations)
3. [Guide Changelog](#markdown-header-guide-changelog)

---------------------------------------
## Introduction
This manual is created to officially state the purpose and explain the usage of NPCBot system


---------------------------------------
## NPCBOTS
NPCBots are hireable pet-like minions. You don't have full control over them, but you can tune their behavior in many ways. Bots will follow you around, buff you, defend you and help you in general. Their main purpose is to support players during their leveling although they can do dungeons and raids, but expect them being stupid in there

Features of the NPCBots:  

- Fighting (via spells, melee, ranged combat)  

- Buffing  

- Healing  

- Resurrecting  

- Acting as a guard (when bot has no owner)  

- Grouping  

- DungeonFinder (they can enter dungeons with you)  

- Raids (they can participate in raids)  

- PvP (they can fight members of your opposing faction)  

- Providing you with consumables (mage, warlock)  

- Receiving buffs and consumables from you  

- Equipping gear  

- Assigning roles  

- Abilities management  

- etc...  


### NPCBot Mod Installation
NPCBots is a TrinityCore mod (https://github.com/TrinityCore/TrinityCore/), currently only 3.3.5 branch is supported  
At the very start of this document you can find a link for TrinityCore revision for the last version of NPCBots. There is no guarantee you will be able to apply the mod if you are using other version of TrinityCore  
Follow TrinityCore Installation Guide (https://TrinityCore.info/) to install the server first  
Download NPCBots.patch and put it into your TrinityCore folder  
Apply the patch using `patch -p1 < NPCBots.patch` command (creating new files)  
(Re)run CMake and (re)build  
Merge worldserver.conf.dist into your worldserver.conf file (NPCBot mod settings)  
Apply SQL files from /TrinityCore/sql/Bots/ to your DB (files starting with `characters_` and `world_` go into your `characters` and `world` DB respectively):
```
1_world_bot_appearance.sql
2_world_bot_extras.sql
3_world_bots.sql
4_world_generate_bot_equips.sql
character_bots.sql
```
And after that you are ready to go

### NPCBot Commands
First of all, to list your bot's stats, use `/bonk` on him (Warning: big list)  

Note that some commands may not be available to all accounts (depending on their access level and permissions set in the RBAC tables). You may need to change your account permissions to enable usage of some commands
Most NPCBot commands are divised by persmissions into two groups: player commands and GM commands
```
KEY:
< > (less/greater than) indicates infon or action you need for the command, can be left out to list info  
 |  (pipe character) indicates parameter options (i.e. this|that  = this OR that)  
 -- (two dashes) indicates information follows about the command  
_TARGET_ indicates that command is used on a selected unit  
```
**COMMAND**: **`.npcbot`**, **`.npcb`** -- (Player command) by itself will list all syntax available  

- **`lookup <CLASS>`** -- (GM command) lookup the NPCBot entries by <CLASS>, returns list of NPCBots as ID, Name and Race  
    - <CLASS> = class ID (i.e. 1 for WARRIORs). **`.npcbot lookup` (`.npcb loo`)** (without the argument) to list class IDs  
    **Example Usage**:  
        - `.npcbot lookup 7` (to list all Shamans)  
        - `.npcb loo 11` (to list all Druids)  
- **`add _TARGET_`** -- (GM command) selected NPCBot becomes yours bypassing the price condition. Only works on NPCBots which have no owner  
    - _TARGET_ = selected NPCBot  
    **Example Usage**:  
        - `.npcbot add`  
        - `.npcb add`  
- **`remove _TARGET_`** -- (GM command) dismisses the NPCBot(s) from control  
    - _TARGET_ = selected NPCBot (dismisses selected NPCBot)  
    - _TARGET_ = selected player (dismisses ALL NPCBots)  
    **Example Usage**:  
        - `.npcbot remove`  
        - `.npcb rem`  
- **`spawn <ENTRY|LINK>`** -- (GM command) spawns a NPCBot in world, NPCBot is saved in DB. Only works in world maps (not instances). Note that unlike other creatures only one instance of each NPCBot can be spawned, but don't worry: there are many NPCBots to choose from  
    - <ENTRY> = ID of NPCBot (can be obtained from lookup list)  
    - <LINK> = creature_template link added by Shift-click (obtained from lookup list)  
    **Example Usage**:  
        - `.npcbot spawn 70001` (spawns NPCBot with ID 70001)  
        - `.npcb sp 70002` (spawn NPCBot with ID 70002)  
        - `.npcb sp [Haromm]` (spawn NPCBot by link)  
- **`delete _TARGET_`** -- (GM command) deletes NPCBot from world, NPCBot is removed from owner if any and deleted from DB  
    - _TARGET_ = selected NPCBot  
    **Example Usage**:  
        - `.npcbot delete`  
        - `.npcb del`  
- **`set`** (GM command)  
    - **`faction <a|h|m|f|factionID> _TARGET_`** -- sets the faction for selected NPCBot  
        - a = 1802 (alliance team)  
        - h = 1801 (horde team)  
        - m = 14 (monster, hostile to all)  
        - f = 35 (friendly to all)  
        - factionID = ID from FactionTemplate.dbc (experts only). It's NOT what you get by using `.lookup faction` command  
        - _TARGET_ = selected NPCBot  
        **Example Usage:**  
            - `.npcbot set faction` (by itself will displays list of subcommands for faction)  
            - `.npcb s f m` (sets the faction of a selected NPCBot to HostileToAll)  
    - **`owner <GUID|NAME> _TARGET_`** -- sets ownership of a selected NPCBot to a specific player  
        - GUID = player DB guid  
        - NAME = player name  
        - _TARGET_ = selected NPCBot  
        **Example Usage:**  
            - `.npcbot set owner 312` (sets the selected NPCBot owner to the player with guid 312)  
            - `.npcb s o Myplayer` (sets the selected NPCBot owner to the player by name `Myplayer`)  
- **`revive _TARGET_`** -- (GM command) revives NPCBot(s)  
    - _TARGET_ = selected NPCBot (revives this NPCBot)  
    - _TARGET_ = selected player (revives all NPCBots of selected player)  
    **Example Usage:**  
        - `.npcbot revive`  
        - `.npcb rev`  
- **`reloadconfig`** -- (GM command) reloads NPCBot system settings  
    - (No arguments)  
    **Example Usage:**  
        - `.npcbot reloadconfig  
- **`command <COMMAND>`** -- (Player command) makes NPCBots to either FOLLOW or STAY (out of combat)  
    - COMMAND = command string  
        - follow, f = FOLLOW mode  
        - stay, s = STAY mode  
        **Example Usage:**  
            - `.npcbot command stay` (NPCBots will stop moving and stay at current location)  
            - `.npcb c f` (NPCBots will follow)  
- **`info _TARGET_`** -- (Player command) shows info on owned bots  
    - _TARGET_ = selected grouped player or self (shows you info on that player)  
    **Example Usage:**  
        - `.npcbot info`  
        - `.npcb in`  
- **`hide`** -- (Player command) forces NPCBots to temporarily disappear. They will teleport off the map and out of the world for until allowed to come back. Cannot be used in combat  
    - (No arguments)  
    **Example Usage:**  
        - `.npcbot hide`  
        - `.npcb h`  
- **`unhide`|`show`** -- (Player command) the opposite of `.npcbot hide` command; your NPCBots will appear shortly. Cannot be used in combat  
    - (No arguments)
    **Example Usage:**  
        - `.npcbot unhide`  
        - `.npcbot show`  
- **`recall`** -- (Player command) forces a NPCBot to move directly on your position. Usable while dead. Designed mostly for situations like when you die and your NPCBots are stuck under textures and in combat at the same time  
    - _TARGET_ = selected NPCBot (move single NPCBot)  
    - _TARGET_ = self (move all NPCBots)  
    **Example Usage:**  
        - `.npcbot recall`  
- **`kill`|`suicide`** -- (Player command) forces a NPCBot to die. Designed for troubleshooting in situations like when NPCBots are not acting normally. This can be caused by a rare bug causing creatures to retain Unit States  
    - _TARGET_ = selected NPCBot (kill single NPCBot troublemaker)  
    - _TARGET_ = self (kill all your NPCBots)  
    **Example Usage:**  
        - `.npcbot kill`  
        - `.npcbot suicide`  

### NPCBot Control and Usage
#### NPCBot Getting started
If this is your first time using an NPCBot, you'll need to do the following to get started:

- `.npcbot lookup`  

This will give you a listing of the available classes with an ID to indicate each class. For example, 1 is the class ID for Warriors.  

_Example Output_:
```
.npcbot lookup #class
Looks up npcbots by #class, and return all matches with their creature ID's.
BOT_CLASS_WARRIOR = 1
BOT_CLASS_PALADIN = 2
BOT_CLASS_HUNTER = 3
BOT_CLASS_ROGUE = 4
BOT_CLASS_PRIEST = 5
BOT_CLASS_DEATH_KNIGHT = 6
BOT_CLASS_SHAMAN = 7
BOT_CLASS_MAGE = 8
BOT_CLASS_WARLOCK = 9
BOT_CLASS_DRUID = 11
BOT_CLASS_BLADEMASTER = 12
BOT_CLASS_SPHYNX = 13
BOT_CLASS_ARCHMAGE = 14
BOT_CLASS_DREADLORD = 15
BOT_CLASS_SPELLBREAKER = 16
BOT_CLASS_DARK_RANGER = 17
```

After you have figured out which class you want to lookup type in:

- `.npcbot lookup 1`
```
Looking for bots of class 1...
70001 - [Llane] Human
70002 - [Thran] Dwarf
70003 - [Lyria] Human
70004 - [Ander] Dwarf
70005 - [Malosh] Orc
70006 - [Granis] Dwarf
...
70038 - [Kerra] Blood Elf
```
Next, you'll select an NPCBot from the list:

- `.npcbot spawn 70003`  
For this example, we'll select Lyria with an ID of 70003

Lyria will spawn at your location as a level 80 Warrior (by default, NPCBots spawn at max level)  
Note that NPCBot you spawned is friendly. By default NPCBots spawn with faction ID set to 35 (friendly to all) But NPCBots will follow realm PvP rules, even if it's a FFAPvP  
Also, NPCBots do not attack anything unless provoked, at which point they may attempt to do whatever it takes to kill their target; they can be very persistent  
**NPCBots can only be spawned in world maps**

Right-clicking on the NPCBot will open a _Gossip Menu_ (which gives you some command choices)  
_Example Output_:
```
You need something?
- <Hire bot>
- Nevermind
```
Note: if you are have a GM mode enabled you will also see a '<Debug>' menu

Next, you'll most likely just select '<Hire bot>' which will popup a confirmation box asking:   
"Do you wish to hire Lyria?", with a cost amount that you can _Accept_ or _Cancel_.
Note: price scales with your level, but rare and elite bots cost more and may require you to be at least level X to hire them

After NPCBot is hired, they will automatically match your level.  
Right-clicking on the NPCBot will open a new Gossip Menu with an assortment of options (described in following subsections). Your NPCBot will follow you around in or out of group, but it's probably a good idea to get them into your group so you can monitor their location on mini-map, or health/mana, etc. Your new hired Gossip Menu will show:
```
- Manage equipment...
- Manage roles...
- Manage formation...
- Manage abilities...
- Give consumable...
- <Create Group>
- You are dismissed
- Pull yourself together, damnit
- Nevermind
- [OPTIONAL options may be displayed here]
- <Create Group (all bots)>
- <Add to group>
- <Add all bots to group>
- <Remove from group>
- [CLASS-SPECIFIC options may be displayed here]
```

For now, select <Create Group> and your NPCBot will join your group and you can begin your adventures!  
As mentioned previously, the other options will be discussed further down this document.

#### NPCBot Getting Around
Whether grouped or not, your NPCBot will follow you around, keeping you buffed along the way (if they can buff), healing you when needed (if it is a healer-type NPCBot), attacking things alongside you and even ressurecting you if you die (if they can ressurect, that is). NPCBots are designed to keep up to your run pace and will mount up on their own version of your mount when you do. In the event that they cannot keep up (due to you moving too fast or they being stuck in combat or in something), your NPCBot will eventually teleport to your location (even if you go into another map).  
NOTE: NPCBots cannot teleport to you when you are in a dungeon, if they are not part of your group.

For the most part, go somewhere and they will follow. Simple as that.
In those cases where following might not be safe or you want to proceed safely, you have a few options.

If your NPCBot is in your direct vicinity, you can target them and emote:
- `/stand` to make your NPCBot stay put
- `/wave` to make your NPCBot follow you again

If your NPCBot is not targetable or in the immediate vicinity (for selection), you can use the commands:

- `.npcbot command stay` (`.npcb c s`) to make all your controlled NPCBots STAY

- `.npcbot command follow` (`.npcb c f`) to make all your controlled NPCBots FOLLOW

In the event your NPCBot is too far away to path to you, your NPCBot will teleport themself to you.
You can also use `.npcbot hide` and then `npcbot unhide` commands to force your NPCBots to teleport to you

When you leave the world your NPCBots aren't hanging around outside the dungeon you decided to log out at. Unless you spawned that NPCBot outside that dungeon. When you log out your NPCBots temporarily become normal free NPCBots (but not hireable because they already have an owner - you) and return to their spawn location. If you picked up your NPCBot in Darnassus, it will return there. If you spawned your NPCBot on the road through the Barrens, it will return there. This can be both annoying and good, spawning NPCBots in a good central location (like in cities), will provide you an easy way to hire them (and coincidentally, they like to hang out and buff passerbys).

#### NPCBot Equipment
NPCBots spawn with some basic equipment and clothes. Some NPCBots however start with some rather powerful weapons but they are only visual and provide no benefits: no damage, no stats. Nothing. They are __purely visual__. In fact, in most cases these weapons are partial to class appearance and will always stay (like Dark Ranger and her trusty bow)  
NPCBots give you the ability to customize their individual gear pieces to make them more effective in combat. Note that visual changes to NPCBot's equipment are not instant

To make changes to their gear, you need to right-click that NPCBot and choose `Manage equipment...` from their post-hire Gossip Menu. You should then see the following:
```
- Show me your inventory
- Auto-equip...
- Main hand...
- Ranged...
- Head...
- Shoulders...
- Chest...
- Waist...
- Legs...
- Feet...
- Wrist...
- Hands...
- Back...
- Shirt...
- Finger 1...
- Finger 2...
- Trinket 1...
- Trinket 2...
- Neck...
- Unequip all
- Update visual
- BACK
```
As you can see, you can gear up pretty much every slot on your NPCBot

- `Show me your inventory` will make the NPCBot whisper you a list of everything they currently have including an item icon (helps to understand which slot the item is equipped into)

- `Auto-equip` will list out all the items you have in YOUR bags that the NPCBot can use. Clicking on one of those items will automatically give it to the NPCBot and equip it into the appropriate slot

- `_(INDIVIDUAL GEAR SLOTS)_` will show you what they have equipped (if any), an option to use their old equipment (if any to start with) OR an unequip option (if you gave them some gear), a listing of any item in YOUR bags that the NPCBot can use in that slot and a BACK option. Selecting any of your bag items will automatically send that item to the NPCBot and have them equip it. The option to use old equipment or unequip gear will have the NPCBot RETURN the gear you gave them BACK to YOUR bags. They will then return to the default gear/state for that slot

- `Unequip all` will have them do just that... dump __ALL__ gear you have given them back into YOUR bags. If you don't have enough space in your bags the excess items will be mailed to you.  NOTE: When firing an NPCBot, any gear you have given your NPCBot will automatically be returned to you

- `BACK` just goes back to the previous menu

#### NPCBot Roles
NPCBot Role management allows you to adjust how they operate overall. The available options are dependent upon the class of the NPCBot you are controlling

To adjust the NPCBot's roles, you need to right-click that NPCBot and choose `_Manage roles..._` from their Gossip Menu. You should then see (dependent upon the class):
```
- Gathering...
- Tanking
- DPS
- Heal
- Ranged
- BACK
```
Clicking on the respective Role will toggle it on/off (changing the icon)

The roles can be a little tricky to understand:

- "Tanking" role only means that NPCBots will try to produce as much threat as possible, use taunt-like abilities to reaggro targets attacking friends and use defensive cooldowns more liberally. This does NOT include attacking anything. Also, if NPCBot has no tanking abilities this role will do nothing

- "DPS" role allows NPCBots to actually deal damage. If this role is disabled NPCBot will not use damaging abilities, not even auto-attack

- "Heal" is the what your healer needs to be enabled. If this role is disabled NPCBots will not even try to heal anything, not even themselves. No, not even in a face of certain death

- "Ranged" role only affects NPCBots' postioning, the distance they will keep from their attack target.
_Example_: Warrior having Tanking + DPS + Ranged role enabled will constantly try to taunt the target and run away, only attacking if target catches up

It's recommended to only enable 1 or 2 specific roles for that class to minimize them switching tactics around alot. The only exception is Priest which can handle DPS, Heal and Ranged roles just fine (they will preserve some mana for healing and resort to wand)

Gathering roles allows NPCBots to collect different ores, herbs, leather and other trade goods. It does NOT allow to track those goods so good luck with that. It also does NOT allow bots to craft anything. NPCBots have their skill assigned according to their level so level 1 NPCBot for example will not be able to mine Mithril

#### NPCBot Formation
Some times you just want your NPCBot close.. or as far away as possible. The formation option allows you to adjust your NPCBot's distance from you.

Select `_Manage formation..._` from their Gossip Menu to adjust the formation. You will see:
```
- Follow distance (current: XX)
- Attack distance...
- BACK
```
NOTE: you will only see "_Attack distance..._" if NPCBot has "Ranged" role assigned
Selecting "_Follow distance_" will open up a popup window that you can enter in an amount. This amount can be anywhere from **0** to **100**. Setting any higher than **100** will default to **100** and any lower than **0** to **0**. Setting the distance to **0** will result in the NPCBot PASSIVELY following you rather closely and not engaging mobs unless you attack

Selecting `_Attack distance..._` will allow you to set ranged attack distance. You will see:
```
- Short range attacks
- Long range attacks
- Exact (0-50)
- BACK
```
NOTE: if "Exact" mode is set, its text will change to
```
- Exact (current: XX)
```
Short range are attacks that are the shortest distance of all ranged attacks for NPCBot's class. For example for paladins it is 10 yards (Judgement range) and for Mages it is 20 yards (Fire Blast range)
Long range attacks are the opposit of short range ones. For most classes this range is about 30-35 yards. This mode is useful when attacking something very dangerous to stand close to
Selecting "_Exact_" will open up a popup window that you can enter in an amount. This amount can be anywhere from **0** to **50**. Same rules as for follow distance.
NOTE: setting exact attack distance to **0** will make NPCBots (and their pets) trying to position themselves on top of their target (ingoring model size)

#### NPCBot Abilities
NPCBots use most of real class spells. Some spells/abilities such as buffs, heals, remove curse/poison, etc. are available through an NPCBot's Abilities menu. Level restrictions apply to NPCBots too, for example Warlock will not be able to use Fear until level 8  
Selecting `_Manage Abilities..._` from the Gossip menu will give you a listing of spells/abilities that they can cast on you or for you. The "Update" option will refresh the spell listing as some spell may be cooled at the moment  
If spell is not listed this doesn't mean NPCBot does not have the spell, probably you just cannot use it manually.  
NPCBots' abilities check algorithm includes finding missing buffs, friends to heal, restocking on consumables (like healthstones), class enchants (Rogue, Shaman), utilities (like using Sprint if falling far behind), spells for party and self, self-heals, finding crowd control targets and finally, attack abilities

Using `_Manage allowed abilities..._` submenu you can make bots not use some of their spells (note though that due to technical restrictions full spell list cannot be displayed so not ANY spell can be disabled)

#### NPCBot Grouping
Although NPCBots will follow their owner around grouped or ungrouped and will usually buff people outside their groups, selecting the ___<Create Group>___ (___<Create Group (all bots)>___) option will have them join your group and properly utilize group buffs for everyone in the group

Grouping is required to properly utilize the DungeonFinder (as you cannot summon NPCBots in or into instances that are ungrouped)

>**NOTES**: There is a known issue where if you are in a group and get disconnected or kicked that the NPCBot(s) will remain in a group with their owner (thus showing up in both groups). The main group needs to kick the NPCBots from the group to be able to invite the owner of the NPCBots. This is the only workaround for that issue, at the moment

>If DungeonFinder group has only one real player loot rules will be set to _Free For All_

>Also, it is advised to fire any additional NPCBots that you might own outside of the group as there have been reports of issues with some quest completions and Random dungeon daily rewards when NPCBots are active but not a part of a group

#### NPCBot Extras
Depending upon the class of the NPCBot, there may be extra options found in the Gossip menu for that NPCBot

For example, Rogue NPCBots will present the options:
```
- Help me pick a lock (XX)
- I need you to refresh poisons
- <Choose poison (Main Hand)>
- <Choose poison (Offhand)>
```
Lockpicks allow you to open locked chests in the world and locked items in your inventory. The skill level (XX) is based on NPCBot's level  
Poisons can be chosen for the expected encounters. You'll have to tell your NPCBot to refresh the poisons when you done

Shaman NPCBots have similar menu for their weapon enchants

Mage NPCBots will give you:
```
- I need food
- I need drink
- I need a refreshment table
```
These options will summon a stack of food or drink for you  
If your level is high enough, the mage NPCBot can summon a refreshment table

Warlock NPCBots will present the options:
```
- I need your healthstone
- I need a soulwell
```
These options will summon a healthstone for you  
If your level is high enough, the warlock NPCBot can summon a soulwell  
Level restrictions are applied here, too

Hunter and Warlock NPCBots (once they reach level 10) also have pet submenu:
```
- <Choose pet type>
```
You are still aware of level restrictions, right?  
Because they don't quite apply to Hunter. He can summon any pet type but exotic pets are only unlocked at 80

Lastly, all NPCBots will have the following extra options:
```
- You are dismissed
- Nevermind
```
`_You are dismissed_` will remove the NPCBot from your control. They will become pissed off, throw all their gear at you and return back to their spawn location. They will also become enraged for 5 minutes to the point of starting attacking anyone attempting to hire them
`_Nevermind_` will simply close out the Gossip menu

### NPCBot Config Settings
If some config settings look ambiguous to you, this section may help you

- **`NpcBot.BaseFollowDistance`**
    - This parameter determines formation size and enemy chase cutoff distance
    - Value range: **0-100**
    - Not saved between log-ins  
    Explanation. Bots group around you in a formation where tanks are in front, melee are on the sides and ranged are in the back. The distance they keep from you is not changed if value of this parameter is 30 or less. Past 30 it is increased linearly up to additional 10 yards between you and a your bots. The distance at which bots start attacking incoming enemies is determined by this parameter as well. This is distance between *you* and the enemy and is about 75% of this paramenter's value. If bot's attack target moves outside of this range bot stops attacking it (unless you attack this target as well) and retreats. **This means** that if this parameter is set low bot actions and chase movement may become erratic. Is this parameter is set to **0** bots will act passively unless you point an attack targets (with your melee attack, only works in combat); this may be useful in case you want bots to attack and retreat, or in situation where blind attack is dangerous and you need bots to attack only targets you want them to
- **`NpcBot.XpReduction`**
    - This parameter allows you to set XP gain percent penalty for players using bots during leveling
    - Value range: **0-90**  
    Explanation. XP amount is reduced by a percentage for every used bot after first one (it doesn't matter if bots are in group with you or not). Two bots are able to do much more damage than one player, especially on low levels. Bots also open great potential for grind. So you may want to punish your players a little. The formula is: **(100 - X \* (Y - 1))%** XP gained, where **X** is XP reduction and **Y** is bots count. *Example: XP reduction is 10, bots count = 4; XP gained: 100 - 10 * (4 - 1) = 70% XP gained*. In any case, overall XP reduction from this parameter will never exceed 90%
- **`NpcBot.HealTargetIconsMask`**
    - This parameter allows players to mark units not under player's control as friends using Target Icons  
    Explanation. Sometimes you need to protect targets other that yourself, escort quests are a good example. With this parameter activated players can set *Raid Icon* on a target they want bots to care about. Bots will treat said target as a member of player's party, heal it if needed and assist it in combat. Parameter itself is a bit mask and consists of a combination of values assigned to each target icon: **Star - 1, Circle - 2, Diamond - 4, Triangle - 8, Moon - 16, Square - 32, Cross - 64, Skull - 128**. *Example: Star, Diamond and Triangle = 1 + 4 + 8 = 13*
- **`NpcBot.Cost`**
    - This parameter determines how much money player has to pay to hire a bot
    - This is how much money player has to pay **at level 80**, for lower levels cost is reduced:
        - level  1-10: cost / 5000
        - level 11-20: cost / 100
        - level 21-30: cost / 20
        - level 31-40: cost / 5
        - level  41+:  cost / 80 \* level  
    Explanation. The value you set is in copper (1 silver = 100 copper, 1 gold = 100 silver = 10000 copper). Rare and Elite bots cost more (**x2** for Rare and **x5** for Elite)
- **`NpcBot.Movements.InterruptFood`**
    - This parameter determines if bots should stop eating and drinking if they move  
    Explanation. By default this parameter is disabled to prevent bots' food and drinks spam since bots try to eat and drink when they have the chance, which is every time they don't do anything even for a fraction of a second
- **`NpcBot.EquipmentDisplay.Enable`**
    - This parameter allows bots to display equipped items other than weapons on their model  
    Explanation. Normally, for creatures game client only draws default model determined by model ID. This parameter force feeds clients information about unit model and items in equipment slots which is generated at server side; so instead of default model client draws player model components including skin color, face, facial hair and others including "equipped" items. The only problem players may encounter comes from a game client bug which can cause a crash at game exit (client crash, not server crash) with error \#132. This bug can be reproduced by changing base model of unit having UNIT_FLAG2_MIRROR_IMAGE more than 4 times in a short period of time, so bots being polymorphed or druids shapeshifting have higher chance of causing this problem

### NPCBot Extra Classes
#### General Information
NPCBot mod features several custom classes inspired by Warcraft III. These bots are ranked Rare, Elite or Rareelite, have different mana increase rate and cannot drink to restore mana, have increased level and hire cost, may have minimum player level requirement. Also, control magic affects them much less, even less than is does players. They are not intended to be as effective as normal classes and/or balanced at any given level. Their main purpose is to support you and other bots. For basic information on certain class use Gossip Menu and click `<Study the creature>`. If you need more info keep on reading  

#### Blademaster
*(Disabled in last version)*  
**Rank: Rare**  
**Level Bonus: +1**  
**Minimum player level: 1**  
**Equipment affects visual: no**  
**Number included: 1**  
**Class specifics:** Very high attack speed, equipped weapon does not affect attack speed, attack power from stats: agility x9, cannot crit with normal attacks, cannot dodge or parry, bonus armor penetration 80%  
Equippable weapon: 2h swords, 2h axes and polearms  
Equippable armor: any (no shield)  
Abilities:

- Netherwalk. Blademaster becomes invisible and moves faster for 30 seconds. If Blademaster breaks invisibility to attack, he will deal 150% damage on first attack
- Mirror Image. Blademaster disappears, creating 1-3 illusions of himself (depends on hero's level). Also dispells all magic from him. Mirror Images deal no real damage and take 200% damage themselves
- Critical Strike (passive). Gives 15% chance to deal critical strike for x2-x4 times normal damage (depends on hero's level)
- Bladestorm (not implemented)  

**Additional info:** Blademaster stands out as a class with highest single target damage capabilities and ability to almost one-shot most things if geared properly. Unfortunately, due to changes in movement mechanic, Blademaster's critical strike animation can not longer be emulated, and thus this class was disabled in last version  

#### Obsidian Destroyer
**Rank: Rareelite**  
**Level Bonus: +3**  
**Minimum player level: 60**  
**Equipment affects visual: weapons only**  
**Number included: 2**  
**Class specifics:** *Very* high resistances, *negative* mana regeneration which cannot be countered by passive mana regeneration effects (like item mp5 stats), cannot mount, no melee attack, stamina bonus +50%, armor bonus: +50%, all damage taken reduced by 33%, attack power from stats: strength x2, spellpower bonus: 50% attack power + 200% intellect + wands, cannot eat  
Equippable weapon: wand**s**  
Equippable armor: mail/plate (no shield), **no jewelry or cape**  
Abilities:

- Devour Magic. Dispels up to 2 magic effect from enemies, up to 2 magic effects and 2 curse effects from allies and damaging summoned units in 20 yards dest area, restoring caster's mana and health (20% mana and 5% health for every dispelled effect)
- Shadow Blast. Empowered attack that deals increased splash damage to targets in a rather large area. Main target takes more damage than others
- Drain Mana. Drains all mana from a random ***friendly*** unit. The amount drained is limited by Obsidian Destroyer's maximum mana. **This ability cannot be disabled**
- Replenish Mana. Energizes surrounding party and raid members within 15 yards for 1% of their maximum mana, affecting up to 10 targets. *This ability drains all mana*
- Replenish Health. Heals surrounding party and raid members within 15 yards for 2% of their maximum health, affecting up to 10 targets. *This ability drains all mana*
- Shadow Armor (passive). Restores mana equal to a percentage of damage taken. This ability only triggers when damage taken is enough to restore 10% of Obsidian Destroyer's mana  

**Additional info:** Obsidian Destroyer in fact derives from a non-hero unit, but received elite status because of the ability to deal insane amounts of damage given the chance, support party of any kind, dispel, purge AND tank at the same time, utilizing abilities of original unit's both forms: statue form and true form  

#### Archmage
**Rank: Rare**  
**Level Bonus: +1**  
**Minimum player level: 20**  
**Equipment affects visual: no**  
**Number included: 1**  
**Class specifics:** Always mounted (ground mount only), no melee attack, armor bonus: 500% intellect, spell damage taken reduced by 35%, spellpower bonus: 100% intellect  
Equippable weapon: staves  
Equippable armor: cloth (no shield)  
Abilities:

- Blizzard. It looks like your typical mage Blizzard but it's in fact a little different. It has no chill effects or anything, but has higher base damage and scales much more with spellpower
- Summon Water Elemental. Archmage Water Elemental has 1 minute duration and 20 sec cooldown, cannot run out of mana and deals more damage since W3 Archmage could have 3 active Elementals
- Brilliance Aura. Increases maximum mana by 10% and mana regeneration by 100% of party and raid members within 40 yards
- Mass Teleport (not implemented)  

**Additional info:** Archmage is most valued for his support capabilities in large groups, although he is very squishy  

#### Dreadlord
**Rank: Rareelite**  
**Level Bonus: +3**  
**Minimum player level: 60**  
**Equipment affects visual: no**  
**Number included: 5**  
**Class specifics:** High resistances, cannot mount, stamina bonus +20%, armor bonus: +50%, all damage taken reduced by 15%, critical strike rating x2, attack power from stats: strength x8, spellpower bonus: 200% stength  
Equippable weapon: axes, maces, swords, 2h axes, 2h maces, 2h swords, polearms, staves, fist weapons, daggers  
Equippable armor: plate (no shield)  
Abilities:

- Carrion Swarm. This ability damages enemies in a very large and long frontal cone, healing Dreadlord for 100% effective damage dealt, can easily restore all health to the Dreadlord, high mana cost. Carrion Swarm deals double damage to incapacitated targets
- Sleep. Puts enemy to sleep for 60 seconds and reduces armor by 100% for the duration. Damage over time effects do not interrupt this effect, only direct damage does
- Vampiric Aura. Increases physical critical damage by 5% and heals party and raid members within 40 yards for 25% (100% for Dreadlord) of damage dealt by melee physical attacks. This heal generates no threat
- Infernal. Summons an Infernal Servant at dest location, damaging and stunning enemy units in the area. Infernal is very resistant to magic and its stats scale with Dreadlord's stats. Infernal burns, dealing damage to surrounding enemies every 2 seconds, 180 sec duration  

**Additional info:** Dreadlord is most useful in a big party with a lot of melee classes and also can be very annoying in pvp if packed with enough haste and armor penetration  

#### Spell Breaker
**Rank: Rare**  
**Level Bonus: +1**  
**Minimum player level: 20**  
**Equipment affects visual: no**  
**Number included: 5**  
**Class specifics:** All spell damage taken reduced by 75%, armor penalty: -30%, attack power from stats: strength x5, block chance + 90%, spellpower bonus: 200% stength  
Equippable weapon: axes, maces, swords, fist weapons, daggers  
Equippable armor: mail/plate  
Abilities:

- Steal Magic. Steals benefical spell from an enemy an transfers it to a nearby ally, or removes a negative spell from an ally and transfers it to a nearby enemy, affects magic and curse effects. Transferred effect duration is limited to a maximum of 5 minutes *and minimum of 5 seconds*
- Feedback (passive). Melee attacks burn target's mana dealing arcane damage. Amount burned is equal to melee damage dealt increased by spell power
- Control Magic (not implemented)  

**Additional info:** Spell Breaker is mostly pure support class incappable of dealing any serious damage, but may also make quick work of some hapless caster, burning all his mana in seconds  

#### Dark Ranger
**Rank: Rareelite**  
**Level Bonus: +3**  
**Minimum player level: 40**  
**Equipment affects visual: no**  
**Number included: 5**  
**Class specifics:** Undead, damage generates no threat, sneak mode if not moving, spell damage taken reduced by 35%, attack power from stats: agility x5 + intellect x2, armor penetration bonus: 50%, crit bonus +20%, dodge bonus +30%, spellpower bonus: 50% intellect  
Equippable weapon: swords, daggers, bows  
Equippable armor: cloth/leather (no shield)  
Abilities:

- Silence. Silences an enemy and nearby targets for 8 seconds. Maximum of 5 targets, 15 sec cooldown
- Black Arrow. Fires a cursed arrow dealing 150% weapon damage and additional damage over time. If affected target dies from Dark Ranger's damage, Dark Minion will spawn from the corpse (does not apply to players), leaving a pile of gore (lootable). Deals 5 times more damage if target is under 20% health. Only affects humanoids, beasts and dragonkin. If target unit's rank is rare, elite of rareelite, spawns elite Minion instead. Maximum 5 Minions, Minions live for 80 seconds and are immune to healing effects
- Drain Life. Drains health from an enemy every second for 5 seconds starting with 0 (6 total ticks), healing Dark Ranger for 200% of the drained amount
- Charm (not implemented)
- Taunt (Dark Minion). Taunts an enemy within melee range to attack Dark Minion instead of Dark Ranger for 5 seconds. One-time use
- Improved Blocking (Dark Minion). Increases chance to block an attack by 60-100% (depends on caster's level) for 6 seconds. One-time use  

**Additional info:** Dark Ranger has most use in solo combined with healer, or as a support in big group due to Silence low cooldown and no other mana sinks  

### NPCBot Occupations
#### Database
NPCBot data is stored in the following locations:

- `characters` DB
    - `characters_npcbot` (created by this mod) contains all information about spawned npcbots  
    Also writes into:
        - `item_instance` (item owner assignment)
- `world` Database (stores information in the following tables)
    - `creature_template` (ids 70001-71000) contains creature base data for bots
    - `creature_equip_template` (ids 70001-71000) contains bots' standard weapons info
    - `npc_text` (ids 70001-71000) custom text for bots' gossip and class descriptions
    - `creature_template_outfits` (created by this mod) contains static display information
    - `creature_template_npcbot_appearance` (created by this mod) contains dynamic display information
    - `creature_template_npcbot_extras` (created by this mod) contains race and class info
    - `creature` contains info about spawned creatures in the world

If you want to make changes to the static template data used for NPCBots, you make adjustments in the `world` database to those specific ids in the above tables (i.e. npcbot model, outfits, etc.)
If you need to remove NPCBot mod completely you need to first manually delete every spawned bot in the world (using .npcbot delete command; you need to remove their equipment first, otherwise the items become inaccessible). Then delete `characters_npcbot`, `creature_template_npcbot_extras` and `creature_template_npcbot_appearance` tables and clean all other used tables of entries by id (70001-71000). `creature_template_outfits` can also be deleted if you are not using Npc Dress Mod.

#### Game World
Bots are counted as active objects (keep grids loaded like players)
Bots are being added to world at server loading (after Map System is started)

#### Bots available to spawn: **301**

---------------------------------------
## Guide Changelog

- **Version 0.7** (_04 Nov 2019_)
    - Added config disambiguation
    - Added info on extra classes
- **Version 0.5.1** (_3 Nov 2019_)
    - Update for branch time-stop-2013
- **Version 0.5** (_30 Oct 2019_)
    - Markdown style fix
- **Version 0.4** (_17 Oct 2019_)
    - Added all extra info

---------------------------------------
