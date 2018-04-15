UPDATE creature_template set ScriptName = 'boss_bjarngrim' where entry =28586;
UPDATE creature_template set ScriptName = 'mob_stormforged_lieutenant' where entry =29240;
DELETE FROM script_texts  where entry IN (-1602001,-1602000,-1602002,-1602003,-1602004,-1602005,-1602006,-1602007,-1602008,-1602009,-1602010);
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1602000,'I am the greatest of my father\'s sons! Your end has come!',14149,1,0,0,'bjarngrim SAY_AGGRO'),
(-1602001,'So ends your curse!',14153,1,0,0,'bjarngrim SAY_SLAY_1'),
(-1602002,'Flesh... is... weak!',14154,1,0,0,'bjarngrim SAY_SLAY_2'),
(-1602003,'...',14155,1,0,0,'bjarngrim SAY_SLAY_3'),
(-1602004,'How can it be...? Flesh is not... stronger!',14156,1,0,0,'bjarngrim SAY_DEATH'),
(-1602005,'Defend yourself, for all the good it will do!',14151,1,0,0,'bjarngrim SAY_BATTLE_STANCE'),
(-1602006,'%s switches to Battle Stance!',0,3,0,0,'bjarngrim EMOTE_BATTLE_STANCE'),
(-1602007,'GRAAAAAH! Behold the fury of iron and steel!',14152,1,0,0,'bjarngrim SAY_BERSEKER_STANCE'),
(-1602008,'%s switches to Berserker Stance!',0,3,0,0,'bjarngrim EMOTE_BERSEKER_STANCE'),
(-1602009,'Give me your worst!',14150,1,0,0,'bjarngrim SAY_DEFENSIVE_STANCE'),
(-1602010,'%s switches to Defensive Stance!',0,3,0,0,'bjarngrim EMOTE_DEFENSIVE_STANCE');
