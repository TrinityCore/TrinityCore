INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1043000,'At last! Naralex can be awakened! Come aid me, brave adventurers!',0,1,0,0,'Disciple SAY_AT_LAST'),
(-1043001,'I must make the necessary preparations before the awakening ritual can begin. You must protect me!',0,0,0,0,'Disciple SAY_MAKE_PREPARATIONS'),
(-1043002,'These caverns were once a temple of promise for regrowth in the Barrens. Now, they are the halls of nightmares.',0,0,0,0,'Disciple SAY_TEMPLE_OF_PROMISE'),
(-1043003,'Come. We must continue. There is much to be done before we can pull Naralex from his nightmare.',0,0,0,0,'Disciple SAY_MUST_CONTINUE'),
(-1043004,'Within this circle of fire I must cast the spell to banish the spirits of the slain Fanglords.',0,0,0,0,'Disciple SAY_BANISH_THE_SPIRITS'),
(-1043005,'The caverns have been purified. To Naralex\'s chamber we go!',0,0,0,0,'Disciple SAY_CAVERNS_PURIFIED'),
(-1043006,'Beyond this corridor, Naralex lies in fitful sleep. Let us go awaken him before it is too late.',0,0,0,0,'Disciple SAY_BEYOND_THIS_CORRIDOR'),
(-1043007,'Protect me brave souls as I delve into this Emerald Dream to rescue Naralex and put an end to this corruption!',0,0,0,0,'Disciple SAY_EMERALD_DREAM'),
(-1043008,'%s begins to perform the awakening ritual on Naralex.',0,2,0,0,'Disciple EMOTE_AWAKENING_RITUAL'),
(-1043009,'%s tosses fitfully in troubled sleep.',0,2,0,0,'Naralex EMOTE_TROUBLED_SLEEP'),
(-1043010,'%s writhes in agony. The Disciple seems to be breaking through.',0,2,0,0,'Naralex EMOTE_WRITHE_IN_AGONY'),
(-1043011,'%s dreams up a horrendous vision. Something stirs beneath the murky waters.',0,2,0,0,'Naralex EMOTE_HORRENDOUS_VISION'),
(-1043012,'This Mutanus the Devourer is a minion from Naralex\'s nightmare no doubt!',0,0,0,0,'Disciple SAY_MUTANUS_THE_DEVOURER'),
(-1043013,'I AM AWAKE, AT LAST!',0,1,0,0,'Naralex SAY_I_AM_AWAKE'),
(-1043014,'At last! Naralex awakes from the nightmare.',0,0,0,0,'Disciple SAY_NARALEX_AWAKES'),
(-1043015,'Ah, to be pulled from the dreaded nightmare! I thank you, my loyal Disciple, along with your brave companions.',0,0,0,0,'Naralex SAY_THANK_YOU'),
(-1043016,'We must go and gather with the other Disciples. There is much work to be done before I can make another attempt to restore the Barrens. Farewell, brave souls!',0,0,0,0,'Naralex SAY_FAREWELL'),
(-1043017,'Attacked! Help get this $N off of me!',0,0,0,0,'Disciple SAY_ATTACKED');

INSERT INTO creature_ai_scripts (creature_id,event_type,event_chance,event_flags,action1_type,action1_param1,action1_param2,comment) VALUES
(3669,6,100,6,34,1,3,'Lord Cobrahn - Set Inst Data on Death'),
(3670,6,100,6,34,2,3,'Lord Pythas - Set Inst Data on Death'),
(3671,6,100,6,34,3,3,'Lady Anacondra - Set Inst Data on Death'),
(3673,6,100,6,34,4,3,'Lord Serpentis - Set Inst Data on Death'),
(3654,6,100,6,34,9,3,'Mutanus the Devourer - Set Inst Data on Death');

DELETE FROM script_waypoint WHERE entry=3678;
INSERT INTO script_waypoint VALUES
(3678, 0, -120.864, 132.825, -79.2972, 5000, 'TYPE_NARALEX_EVENT'),
(3678, 1, -109.944, 155.417, -80.4659, 0, ''),
(3678, 2, -106.104, 198.456, -80.5970, 0, ''),
(3678, 3, -110.246, 214.763, -85.6669, 0, ''),
(3678, 4, -105.609, 236.184, -92.1732, 0, 'TYPE_NARALEX_PART1'),
(3678, 5, -93.5297, 227.956, -90.7522, 0, ''),
(3678, 6, -85.3155, 226.976, -93.1286, 0, ''),
(3678, 7, -62.1510, 206.673, -93.5510, 0, ''),
(3678, 8, -45.0534, 205.580, -96.2435, 0, ''),
(3678, 9, -31.1235, 234.225, -94.0841, 0, ''),
(3678, 10, -49.2158, 269.141, -92.8442, 0, ''),
(3678, 11, -54.1220, 274.717, -92.8442, 31000, 'TYPE_NARALEX_PART2'),
(3678, 12, -58.9650, 282.274, -92.5380, 0, ''),
(3678, 13, -38.3566, 306.239, -90.0192, 0, ''),
(3678, 14, -28.8928, 312.842, -89.2155, 0, ''),
(3678, 15, -1.58198, 296.127, -85.5984, 0, ''),
(3678, 16, 9.89992, 272.008, -85.7759, 0, ''),
(3678, 17, 26.8162, 259.218, -87.3938, 0, ''),
(3678, 18, 49.1166, 227.259, -88.3379, 0, ''),
(3678, 19, 54.4171, 209.316, -90.0000, 1500, 'SAY_BEYOND_THIS_CORRIDOR'),
(3678, 20, 71.0380, 205.404, -93.0422, 0, ''),
(3678, 21, 81.5941, 212.832, -93.0154, 0, ''),
(3678, 22, 94.3376, 236.933, -95.8261, 0, ''),
(3678, 23, 114.619, 235.908, -96.0495, 0, ''),
(3678, 24, 114.777, 237.155, -96.0304, 2500, 'NARALEX_EVENT_FINISHED');

UPDATE creature_template SET ScriptName = 'npc_disciple_of_naralex' WHERE entry = 3678;
UPDATE instance_template SET script = 'instance_wailing_caverns' WHERE map = 43;
