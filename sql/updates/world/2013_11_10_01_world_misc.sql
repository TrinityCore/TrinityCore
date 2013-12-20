UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_mennu_the_betrayer' WHERE entry=17991;
DELETE FROM creature_ai_scripts WHERE creature_id=17991;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -98 AND -93;
