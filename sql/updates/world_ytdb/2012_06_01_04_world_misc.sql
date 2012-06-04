-- Creature addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (26421,26321,26333);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26421,0,0,1,0, NULL), -- Woodlands Walker
(26321,0,0,1,64, '47044'), -- Lothalor Ancient (Cosmetic - Confused State Visual (Big))
(26333,0,0,1,0, '32566 46967'); -- Corrupted Lothalor Ancient (Purple Banish State, Purple Banish State - Breath)

-- Woodlands Walker already has spellclick spell: 47575 (Strengthen the Ancients: On Interact Dummy to Woodlands Walker)

-- Monster emotes
DELETE FROM `creature_text` WHERE `entry` IN (26421,26321);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(26421, 0, 0, 'Breaking off a piece of its bark, the %s hands it to you before departing.', 16, 0, 100, 0, 0, 0, 'Woodlands Walker'),
(26421, 1, 0, 'The %s is angered by your request and attacks!', 16, 0, 100, 0, 0, 0, 'Woodlands Walker'),
(26321, 0, 0, 'The %s gives you its thanks.', 16, 0, 100, 0, 0, 1525, 'Lothalor Ancient');

-- Assign scripts to spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (47575,47530);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47575, 'spell_q12096_q12092_dummy'),
(47530, 'spell_q12096_q12092_bark');

/*
- player spellclicks Woodlands Walker, casts 47575 on the tree Woodlands Walker: two outcomes:

- - tree turns enemy:
* say The %s is angered by your request and attacks!
* change faction to 14
* start attack

- - tree stays friendly:
* cast 47550 (Create Bark of the Walkers)on player
* say Breaking off a piece of its bark, the %s hands it to you before departing.
* despawn


- player uses item on Lothalor Ancient (47530 (Bark of the Walkers)):
* tree says The %s gives you its thanks.
* aura 47044 (Cosmetic - Confused State Visual (Big)) is removed
* despawns after 4 secs
*/
