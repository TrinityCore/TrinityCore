UPDATE creature_template SET ScriptName='' WHERE entry=466;
UPDATE script_texts SET content_default='UNUSED', language=0, comment='REUSE ME' WHERE entry=-1000005;

UPDATE `creature_template` SET `ScriptName`='npc_aged_dying_ancient_kodo' WHERE `entry` IN (4700,4701,4702,11627);

DELETE FROM script_texts WHERE entry BETWEEN -1000430 AND -1000428;
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000428, 'Ah...the wondrous sound of kodos. I love the way they make the ground shake... inspect the beast for me.',0,0,0,0,'kodo round SAY_SMEED_HOME_1'),
(-1000429, 'Hey, look out with that kodo! You had better inspect that beast before i give you credit!',0,0,0,0,'kodo round SAY_SMEED_HOME_2'),
(-1000430, 'That kodo sure is a beauty. Wait a minute, where are my bifocals? Perhaps you should inspect the beast for me.',0,0,0,0,'kodo round SAY_SMEED_HOME_3');