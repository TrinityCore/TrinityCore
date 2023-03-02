-- Water Strider Water Walking
DELETE FROM `spell_linked_spell` WHERE `spell_effect` = -143333;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-118089, -143333, 0, 'Remove 143333 aura on 118089 aura remove'),
(-127271, -143333, 0, 'Remove 143333 aura on 127271 aura remove'),
(-127272, -143333, 0, 'Remove 143333 aura on 127272 aura remove'),
(-127274, -143333, 0, 'Remove 143333 aura on 127274 aura remove'),
(-127278, -143333, 0, 'Remove 143333 aura on 127278 aura remove');

DELETE FROM `spell_proc_event` WHERE `entry` = 143333;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`) VALUE
(143333, 127);

