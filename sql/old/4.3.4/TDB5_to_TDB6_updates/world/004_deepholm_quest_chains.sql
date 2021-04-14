-- http://www.wowwiki.com/Deepholm_quests

/*
 * Upper World Pillar Fragment
 */

-- Hero's Call: Deepholm! / Warchief's Command: Deepholm! (optional)
-- The Maelstrom http://www.wowhead.com/quest=27203
-- Deepholm, Realm of Earth
UPDATE `quest_template` SET `PrevQuestId` = 27203 WHERE `Id` = 27123;
-- Gunship Down
UPDATE `quest_template` SET `PrevQuestId` = 27123 WHERE `Id` = 26245;
-- Captain's Log
UPDATE `quest_template` SET `PrevQuestId` = 26245, `NextQuestId` = 26247, `ExclusiveGroup` = -26246 WHERE `Id` = 26246;
-- Elemental Energy
UPDATE `quest_template` SET `PrevQuestId` = 26245, `NextQuestId` = 26247, `ExclusiveGroup` = -26246 WHERE `Id` = 27136;
-- The Earth Claims All
UPDATE `quest_template` SET `PrevQuestId` = 26245, `NextQuestId` = 26247, `ExclusiveGroup` = -26246 WHERE `Id` = 26244;
-- Diplomacy First
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26247;
-- All Our Friends Are Dead
UPDATE `quest_template` SET `PrevQuestId` = 26247, `NextQuestId` = 26251, `ExclusiveGroup` = -26248 WHERE `Id` = 26248;
-- The Admiral's Cabin
UPDATE `quest_template` SET `PrevQuestId` = 26247 WHERE `Id` = 26249;
-- Without a Captain or Crew
UPDATE `quest_template` SET `PrevQuestId` = 26249, `NextQuestId` = 26251, `ExclusiveGroup` = -26248 WHERE `Id` = 26427;
-- Take No Prisoners
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26251;
-- On Second Thought, Take One Prisoner
UPDATE `quest_template` SET `PrevQuestId` = 26251 WHERE `Id` = 26250;
-- Some Spraining to Do
UPDATE `quest_template` SET `PrevQuestId` = 26250 WHERE `Id` = 26254;
-- Return to the Temple of Earth
UPDATE `quest_template` SET `PrevQuestId` = 26254 WHERE `Id` = 26255;
-- Deathwing's Fall
UPDATE `quest_template` SET `PrevQuestId` = 26255 WHERE `Id` = 26258;
-- Blood of the Earthwarder
UPDATE `quest_template` SET `PrevQuestId` = 26258 WHERE `Id` = 26259;
-- Bleed the Bloodshaper
UPDATE `quest_template` SET `PrevQuestId` = 26259 WHERE `Id` = 26256;
-- Question the Slaves
UPDATE `quest_template` SET `PrevQuestId` = 26256 WHERE `Id` = 26261;
-- The Forgemaster's Log
UPDATE `quest_template` SET `PrevQuestId` = 26261 WHERE `Id` = 26260;
-- Silvermarsh Rendezvous
UPDATE `quest_template` SET `PrevQuestId` = 26260 WHERE `Id` = 27007;
-- Quicksilver Submersion
UPDATE `quest_template` SET `PrevQuestId` = 27007 WHERE `Id` = 27010;
-- Twilight Research
UPDATE `quest_template` SET `PrevQuestId` = 27010 WHERE `Id` = 27100;
-- Maziel's Revelation
UPDATE `quest_template` SET `PrevQuestId` = 27100 WHERE `Id` = 27101;
-- Maziel's Ascendancy
UPDATE `quest_template` SET `PrevQuestId` = 27101 WHERE `Id` = 27102;
-- The Twilight Overlook
UPDATE `quest_template` SET `PrevQuestId` = 27102 WHERE `Id` = 27061;
-- Big Game, Big Bait 
UPDATE `quest_template` SET `PrevQuestId` = 27061, `NextQuestId` = 26771, `ExclusiveGroup` = -26768 WHERE `Id` = 26766;
-- To Catch a Dragon
UPDATE `quest_template` SET `PrevQuestId` = 27061, `NextQuestId` = 26771, `ExclusiveGroup` = -26768 WHERE `Id` = 26768;
-- Testing the Trap
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26771;
-- Abyssion's Minions
UPDATE `quest_template` SET `PrevQuestId` = 26771, `NextQuestId` = 26876, `ExclusiveGroup` = -26857 WHERE `Id` = 26857;
-- Block the Gates
UPDATE `quest_template` SET `PrevQuestId` = 26771, `NextQuestId` = 26876, `ExclusiveGroup` = -26857 WHERE `Id` = 26861;
-- The World Pillar Fragment
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26876;

/*
 * Middle World Pillar Fragment
 */

-- Where's Goldmine?
UPDATE `quest_template` SET `PrevQuestId` = 26876 WHERE `Id` = 26409;
-- Explosive Bonding Compound
UPDATE `quest_template` SET `PrevQuestId` = 26409 WHERE `Id` = 26410;
-- Something that Burns
UPDATE `quest_template` SET `PrevQuestId` = 26410 WHERE `Id` = 27135;
-- Apply and Flash Dry
UPDATE `quest_template` SET `PrevQuestId` = 27135 WHERE `Id` = 26411;
-- Take Him to the Earthcaller
UPDATE `quest_template` SET `PrevQuestId` = 26411 WHERE `Id` = 26413;
-- To Stonehearth's Aid
UPDATE `quest_template` SET `PrevQuestId` = 26413 WHERE `Id` = 26484;
-- The Quaking Fields
UPDATE `quest_template` SET `PrevQuestId` = 26484 WHERE `Id` = 27931;
-- The Axe of Earthly Sundering
UPDATE `quest_template` SET `PrevQuestId` = 27931, `NextQuestId` = 27934, `ExclusiveGroup` = -27932 WHERE `Id` = 27932;
-- Elemental Ore
UPDATE `quest_template` SET `PrevQuestId` = 27931, `NextQuestId` = 27934, `ExclusiveGroup` = -27932 WHERE `Id` = 27933;
-- One With the Ground
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 27934;
-- Bring Down the Avalanche
UPDATE `quest_template` SET `PrevQuestId` = 27934 WHERE `Id` = 27936;
-- Stonefather's Boon
UPDATE `quest_template` SET `PrevQuestId` = 27936 WHERE `Id` = 26499;
-- Sealing the Way
UPDATE `quest_template` SET `PrevQuestId` = 26499 WHERE `Id` = 26501;
-- Shatter Them!
UPDATE `quest_template` SET `PrevQuestId` = 26501, `NextQuestId` = 26591, `ExclusiveGroup` = -26537 WHERE `Id` = 26537;
-- We're Surrounded
UPDATE `quest_template` SET `PrevQuestId` = 27936 WHERE `Id` = 26500;
-- Thunder Stones
UPDATE `quest_template` SET `PrevQuestId` = 26500 WHERE `Id` = 26502;
-- Fixer Upper
UPDATE `quest_template` SET `PrevQuestId` = 26501, `NextQuestId` = 26591, `ExclusiveGroup` = -26537 WHERE `Id` = 26564;
-- Battlefront Triage
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26591;
-- Troggzor the Earthinator
UPDATE `quest_template` SET `PrevQuestId` = 26591 WHERE `Id` = 26625;
-- Rush Delivery
UPDATE `quest_template` SET `PrevQuestId` = 26625 WHERE `Id` = 27126;
-- Close Escort
UPDATE `quest_template` SET `PrevQuestId` = 27126 WHERE `Id` = 26632;
-- Keep Them off the Front
UPDATE `quest_template` SET `PrevQuestId` = 26632 WHERE `Id` = 26755;
-- Reactivate the Constructs
UPDATE `quest_template` SET `PrevQuestId` = 26755, `NextQuestId` = 26834, `ExclusiveGroup` = -26762 WHERE `Id` = 26762;
-- Mystic Masters
UPDATE `quest_template` SET `PrevQuestId` = 26755, `NextQuestId` = 26834, `ExclusiveGroup` = -26762 WHERE `Id` = 26770;
-- Down Into the Chasm
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26834;
-- Sprout No More
UPDATE `quest_template` SET `PrevQuestId` = 26834, `NextQuestId` = 26835, `ExclusiveGroup` = -26791 WHERE `Id` = 26791;
-- Fungal Monstrosities
UPDATE `quest_template` SET `PrevQuestId` = 26834, `NextQuestId` = 26835, `ExclusiveGroup` = -26791 WHERE `Id` = 26792;
-- A Slight Problem
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26835;
-- Rescue the Stonefather... and Flint
UPDATE `quest_template` SET `PrevQuestId` = 26835 WHERE `Id` = 26836;
-- The Hero Returns
UPDATE `quest_template` SET `PrevQuestId` = 26836 WHERE `Id` = 27937;
-- The Middle Fragment 
UPDATE `quest_template` SET `PrevQuestId` = 27937 WHERE `Id` = 27938;

/*
 * Lower World Pillar Fragment
 */

-- The Very Earth Beneath Our Feet
UPDATE `quest_template` SET `PrevQuestId` = 27938 WHERE `Id` = 26326;
-- Crumbling Defenses 
UPDATE `quest_template` SET `PrevQuestId` = 26326, `NextQuestId` = 26315, `ExclusiveGroup` = -26312 WHERE `Id` = 26312;
-- Core of Our Troubles
UPDATE `quest_template` SET `PrevQuestId` = 26326, `NextQuestId` = 26315, `ExclusiveGroup` = -26312 WHERE `Id` = 26313;
-- On Even Ground 
UPDATE `quest_template` SET `PrevQuestId` = 26326, `NextQuestId` = 26315, `ExclusiveGroup` = -26312 WHERE `Id` = 26314;
-- Imposing Confrontation
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26315;
-- Rocky Relations
UPDATE `quest_template` SET `PrevQuestId` = 26315 WHERE `Id` = 26328;
-- Loose Stones
UPDATE `quest_template` SET `PrevQuestId` = 26328, `NextQuestId` = 26426, `ExclusiveGroup` = -26375 WHERE `Id` = 26375;
-- Hatred Runs Deep 
UPDATE `quest_template` SET `PrevQuestId` = 26328, `NextQuestId` = 26426, `ExclusiveGroup` = -26375 WHERE `Id` = 26376;
-- Unsolid Ground 
UPDATE `quest_template` SET `PrevQuestId` = 26328, `NextQuestId` = 26426, `ExclusiveGroup` = -26375 WHERE `Id` = 26377;
-- Violent Gale
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26426;
-- Depth of the Depths
UPDATE `quest_template` SET `PrevQuestId` = 26426 WHERE `Id` = 26869;
-- A Rock Amongst Many
UPDATE `quest_template` SET `PrevQuestId` = 26869 WHERE `Id` = 26871;
-- Entrenched
UPDATE `quest_template` SET `PrevQuestId` = 26871 WHERE `Id` = 26436;
-- Making Things Crystal Clear
UPDATE `quest_template` SET `PrevQuestId` = 26436, `NextQuestId` = 28869, `ExclusiveGroup` = -26437 WHERE `Id` = 26437;
-- Intervention
UPDATE `quest_template` SET `PrevQuestId` = 26436, `NextQuestId` = 28869, `ExclusiveGroup` = -26437 WHERE `Id` = 26438;
-- Putting the Pieces Together
UPDATE `quest_template` SET `PrevQuestId` = 26436, `NextQuestId` = 28869, `ExclusiveGroup` = -26437 WHERE `Id` = 26439;
-- Pebble
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 28869;
-- Clingy
UPDATE `quest_template` SET `PrevQuestId` = 28869 WHERE `Id` = 26440;
-- So Big, So Round...
UPDATE `quest_template` SET `PrevQuestId` = 26440 WHERE `Id` = 26441;
-- Rock Bottom
UPDATE `quest_template` SET `PrevQuestId` = 26441 WHERE `Id` = 26575;
-- Petrified Delicacies
UPDATE `quest_template` SET `PrevQuestId` = 26575 WHERE `Id` = 26507;
-- Steady Hand
UPDATE `quest_template` SET `PrevQuestId` = 26507 WHERE `Id` = 26576;
-- Don't. Stop. Moving.
UPDATE `quest_template` SET `PrevQuestId` = 26576 WHERE `Id` = 26656;
-- Hard Falls 
UPDATE `quest_template` SET `PrevQuestId` = 26656, `NextQuestId` = 26659, `ExclusiveGroup` = -26657 WHERE `Id` = 26657;
-- Fragile Values
UPDATE `quest_template` SET `PrevQuestId` = 26656, `NextQuestId` = 26659, `ExclusiveGroup` = -26657 WHERE `Id` = 26658;
-- Resonating Blow
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26659;
-- Rocky Upheaval
UPDATE `quest_template` SET `PrevQuestId` = 26659 WHERE `Id` = 26577;
-- Doomshrooms
UPDATE `quest_template` SET `PrevQuestId` = 26577, `NextQuestId` = 26584, `ExclusiveGroup` = -26578 WHERE `Id` = 26578;
-- Gone Soft
UPDATE `quest_template` SET `PrevQuestId` = 26577, `NextQuestId` = 26584, `ExclusiveGroup` = -26578 WHERE `Id` = 26579;
-- Familiar Intruders
UPDATE `quest_template` SET `PrevQuestId` = 26577 WHERE `Id` = 26580;
-- A Head Full of Wind
UPDATE `quest_template` SET `PrevQuestId` = 26580 WHERE `Id` = 26581;
-- Unnatural Causes
UPDATE `quest_template` SET `PrevQuestId` = 26581, `NextQuestId` = 26584, `ExclusiveGroup` = -26578 WHERE `Id` = 26582;
-- Shaken and Stirred
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26584;
-- Wrath of the Fungalmancer
UPDATE `quest_template` SET `PrevQuestId` = 26584, `NextQuestId` = 26750, `ExclusiveGroup` = -26583 WHERE `Id` = 26583;
-- Corruption Destruction 
UPDATE `quest_template` SET `PrevQuestId` = 26584, `NextQuestId` = 26750, `ExclusiveGroup` = -26583 WHERE `Id` = 26585;
-- At the Stonemother's Call
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26750;
-- Audience with the Stonemother
UPDATE `quest_template` SET `PrevQuestId` = 26750 WHERE `Id` = 26752;
-- Rallying the Earthen Ring
UPDATE `quest_template` SET `PrevQuestId` = 26752 WHERE `Id` = 26827;
-- Our Part of the Bargain
UPDATE `quest_template` SET `PrevQuestId` = 26827 WHERE `Id` = 26828;
-- The Stone March 
UPDATE `quest_template` SET `PrevQuestId` = 26828, `NextQuestId` = 26833, `ExclusiveGroup` = -26829 WHERE `Id` = 26829;
-- The Twilight Flight
UPDATE `quest_template` SET `PrevQuestId` = 26828, `NextQuestId` = 26833, `ExclusiveGroup` = -26829 WHERE `Id` = 26831;
-- Therazane's Mercy 
UPDATE `quest_template` SET `PrevQuestId` = 26828, `NextQuestId` = 26833, `ExclusiveGroup` = -26829 WHERE `Id` = 26832;
-- Word In Stone
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 26833;
-- Undying Twilight
UPDATE `quest_template` SET `PrevQuestId` = 26833 WHERE `Id` = 26875;
-- The Binding
UPDATE `quest_template` SET `PrevQuestId` = 26875 WHERE `Id` = 26971;
-- The Stone Throne
UPDATE `quest_template` SET `PrevQuestId` = 26971 WHERE `Id` = 26709;
