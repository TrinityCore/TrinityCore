DELETE FROM `achievement_reward` WHERE `ID` IN (40942,40943);
INSERT INTO `achievement_reward` (`ID`,`TitleA`,`TitleH`,`ItemID`,`Sender`,`Subject`,`Body`,`MailTemplateID`) VALUES
(40942,0,0,236953,219226,'Undermine Crest Analysis','$n,\r\n\r\nI have been doing some digging and I think I hit the jackpot. These Carved Crests are actually quite similar to Runed Crests once you start breaking them down to the fundamental level.\r\n\r\nWith this knowledge, I should be able to transmute your Carved Undermine Crests into Runed Undermine Crests!\r\n\r\nSee you in Dornogal,\r\nVaskarn',0),
(40943,0,0,236953,219226,'Undermine Crest Advancements','My friend!\r\n\r\nCuzolth and I have been analyzing these Undermine Crests and I think we finally unearthed their secrets.\r\n\r\nI should be able to transmute your Weathered Undermine Crests into Carved Undermine Crests now. Make haste and meet me in Dornogal at once!\r\n\r\nYour friend,\r\nVaskarn',0);

DELETE FROM `item_loot_template` WHERE `Entry`=236953 AND `ItemType`=2 AND `Item`=3008;
INSERT INTO `item_loot_template` (`Entry`,`ItemType`,`Item`,`MinCount`,`MaxCount`,`Comment`) VALUES
(236953,2,3008,100,100,'Crimson Valorstone - 100 Valorstones');
