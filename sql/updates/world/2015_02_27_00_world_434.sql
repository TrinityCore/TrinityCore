DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 101062;
INSERT INTO `spell_linked_spell` VALUES (101062,-88688,0,'Flash Light must remove Surge of Light aura');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 24 AND `SourceEntry` = 88687);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 24 AND `SourceEntry` = 88690);
INSERT INTO `conditions` VALUES 
(24,0,88687,0,0,1,0,88688,0,0,1,0,0,'','Surge of light R1 must not be proc if we already have the aura'),
(24,0,88690,0,0,1,0,88688,0,0,1,0,0,'','Surge of light R2 must not be proc if we already have the aura');

DELETE FROM `spell_proc_event` WHERE `entry` = 88687;
DELETE FROM `spell_proc_event` WHERE `entry` = 88690;

INSERT INTO `spell_proc_event` VALUES -- Corrected SpellClassMask of Surge of Light
(88687,0,6,7296,4,0,0,0,0,3,0), -- Surge of light Rank 1
(88690,0,6,7296,4,0,0,0,0,6,0); -- Surge of light Rank 2