-- Fixes to Highlord Demitrian smart_scripts
UPDATE smart_scripts SET `comment`='Highlord Demitrian - On Gossip Complete - Add Item Vessel of Rebirth' WHERE entryorguid=14347 AND event_type=62;
UPDATE smart_scripts SET action_param2=6, action_param3=60000, target_type=8, target_x='-6241.771973',target_y='1717.143311',target_z='4.250421',target_o='0.680879',`comment`='Highlord Demitrian - On Quest Thunderaan the Windseeker Finished - Summon Creature Prince Thunderaan at XYZO' WHERE entryorguid=14347 AND event_type=20;
