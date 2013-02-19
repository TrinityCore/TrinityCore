-- Converts GOSSIP_OPTION display text from Generic to English
-- Fixes some problems with GOSSIP_OPTION_OUTDOORPVP, the columns were shifted over one for some reason, seems to have been a typo.
UPDATE `gossip_menu_option` SET `option_text`= 'I want to travel fast' WHERE `option_text`= 'GOSSIP_OPTION_TAXIVENDOR';
UPDATE `gossip_menu_option` SET `option_text`= 'I want to join the Battle Ground' WHERE `option_text`= 'GOSSIP_OPTION_BATTLEFIELD';
UPDATE `gossip_menu_option` SET `option_text`= 'Bring me back to life' WHERE `option_text`= 'GOSSIP_OPTION_SPIRITGUIDE' OR `option_text`= 'GOSSIP_OPTION_SPIRITHEALER';
UPDATE `gossip_menu_option` SET `option_text`= 'Make this inn my home' WHERE `option_text`= 'GOSSIP_OPTION_INNKEEPER';
UPDATE `gossip_menu_option` SET `option_text`= 'Show me my bank' WHERE `option_text`= 'GOSSIP_OPTION_BANKER';
UPDATE `gossip_menu_option` SET `option_text`= 'I''d like to stable my pet here' WHERE `option_text`= 'GOSSIP_OPTION_STABLEPET';
UPDATE `gossip_menu_option` SET `option_text`= 'I want to create a guild crest' WHERE `option_text`= 'GOSSIP_OPTION_TABARDDESIGNER';
UPDATE `gossip_menu_option` SET `option_text`= 'Auction!' WHERE `option_text`= 'GOSSIP_OPTION_AUCTIONEER';
UPDATE `gossip_menu_option` SET `option_text`= 'Purchase a Dual Talent Specialization'  WHERE `option_text`= 'GOSSIP_OPTION_LEARNDUALSPEC';
UPDATE `gossip_menu_option` SET `option_text`= 'I wish to unlearn my pet''s skills'  WHERE `option_text`= 'GOSSIP_OPTION_UNLEARNPETSKILLS';
UPDATE `gossip_menu_option` SET `option_text`= 'I wish to unlearn my talents'  WHERE `option_text`= 'GOSSIP_OPTION_UNLEARNTALENTS';
UPDATE `gossip_menu_option` SET `option_text`= 'Train me!'  WHERE `option_text`= 'GOSSIP_OPTION_TRAINER';
UPDATE `gossip_menu_option` SET `option_text`= 'I want to browse your goods'  WHERE `option_text`= 'GOSSIP_OPTION_VENDOR' OR `option_text`= 'GOSSIP_OPTION_ARMORER';
UPDATE `gossip_menu_option` SET `option_text`= 'How do I form a guild?'  WHERE `option_text`= 'GOSSIP_OPTION_PETITIONER';
UPDATE `gossip_menu_option` SET `option_id`=19,`npc_option_npcflag`=536870912,`action_menu_id`=0 WHERE `option_text`= 'GOSSIP_OPTION_OUTDOORPVP';
