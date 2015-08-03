-- Darkwraith
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=15657 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Plaguehound
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=8598 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Amani Berserker
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=15643 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Enraged Wraith
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=17086 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Anok'suten
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=16357 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Bloodscalp Warrior
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=587 AND `source_type`=0 AND `id`=2 AND `link`=3;
-- Bloodscalp Berserker
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=597 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Commander Aggro'gosh
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=2464 AND `source_type`=0 AND `id`=3 AND `link`=4;
-- Vilebranch Berserker 
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=2643 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Hungering Wraith
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=1802 AND `source_type`=0 AND `id`=1 AND `link`=2;
-- Dark Strand Enforcer
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=3727 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Scarlet Myrmidon
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=4295 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Ymirjar Flesh Hunter
UPDATE `smart_scripts` SET `event_flags`=7 WHERE  `entryorguid`=26670 AND `source_type`=0 AND `id`=27 AND `link`=28;
-- Startup Errors
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=22895 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=1487 AND `source_type`=0 AND `id`=8 AND `link`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=2245 AND `source_type`=0 AND `id`=14 AND `link`=15;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=2375 AND `source_type`=0 AND `id`=8 AND `link`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=16344 AND `source_type`=0 AND `id`=8 AND `link`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=29174 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=29174 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=29174 AND `source_type`=0 AND `id`=4 AND `link`=5;
-- Timed action scripts aren't supposed to have links set on them
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=3 AND `link`=0;
-- Aforementioned issue about links on timed scripts
UPDATE `smart_scripts` SET `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE  `entryorguid`=305400 AND `source_type`=9 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=15938 AND `source_type`=0 AND `id`=7 AND `link`=8;
-- This one had messed up ID's too
UPDATE `smart_scripts` SET `id`=5, `link`=6 WHERE  `entryorguid`=19456 AND `source_type`=0 AND `id`=6 AND `link`=7;
UPDATE `smart_scripts` SET `id`=6 WHERE  `entryorguid`=19456 AND `source_type`=0 AND `id`=7 AND `link`=0;
UPDATE `smart_scripts` SET `id`=7 WHERE  `entryorguid`=19456 AND `source_type`=0 AND `id`=8 AND `link`=0;
UPDATE `smart_scripts` SET `id`=8 WHERE  `entryorguid`=19456 AND `source_type`=0 AND `id`=9 AND `link`=0;
UPDATE `smart_scripts` SET `id`=9 WHERE  `entryorguid`=19456 AND `source_type`=0 AND `id`=10 AND `link`=0;
