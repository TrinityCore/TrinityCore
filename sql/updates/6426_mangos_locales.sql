
ALTER TABLE locales_creature
  ADD COLUMN name_loc8 varchar(100) NOT NULL default '' AFTER name_loc7,
  ADD COLUMN subname_loc8 varchar(100) default NULL AFTER subname_loc7;

UPDATE locales_creature SET name_loc8 = name_loc7, subname_loc8 = subname_loc7;

ALTER TABLE locales_gameobject
  ADD COLUMN name_loc8 varchar(100) NOT NULL default '' AFTER name_loc7,
  ADD COLUMN castbarcaption_loc8 varchar(100) NOT NULL default '' AFTER castbarcaption_loc7;

UPDATE locales_gameobject SET name_loc8 = name_loc7, castbarcaption_loc8 = castbarcaption_loc7;

ALTER TABLE locales_item
  ADD COLUMN name_loc8 varchar(100) NOT NULL default '' AFTER name_loc7,
  ADD COLUMN description_loc8 varchar(255) default NULL AFTER description_loc7;

UPDATE locales_item SET name_loc8 = name_loc7, description_loc8 = description_loc7;

ALTER TABLE locales_page_text
  ADD COLUMN Text_loc8 longtext AFTER Text_loc7;

UPDATE locales_page_text SET Text_loc8 = Text_loc7;

ALTER TABLE locales_quest
  ADD COLUMN Title_loc8 text AFTER Title_loc7,
  ADD COLUMN Details_loc8 text AFTER Details_loc7,
  ADD COLUMN Objectives_loc8 text AFTER Objectives_loc7,
  ADD COLUMN OfferRewardText_loc8 text AFTER OfferRewardText_loc7,
  ADD COLUMN RequestItemsText_loc8 text AFTER RequestItemsText_loc7,
  ADD COLUMN EndText_loc8 text AFTER EndText_loc7,
  ADD COLUMN ObjectiveText1_loc8 text AFTER ObjectiveText1_loc7,
  ADD COLUMN ObjectiveText2_loc8 text AFTER ObjectiveText2_loc7,
  ADD COLUMN ObjectiveText3_loc8 text AFTER ObjectiveText3_loc7,
  ADD COLUMN ObjectiveText4_loc8 text AFTER ObjectiveText4_loc7;

UPDATE locales_quest SET Title_loc8 = Title_loc7,
                         Details_loc8 = Details_loc7,
                         Objectives_loc8 = Objectives_loc7,
                         OfferRewardText_loc8 = OfferRewardText_loc7,
                         RequestItemsText_loc8 = RequestItemsText_loc7,
                         EndText_loc8 = EndText_loc7,
                         ObjectiveText1_loc8 = ObjectiveText1_loc7,
                         ObjectiveText2_loc8 = ObjectiveText2_loc7,
                         ObjectiveText3_loc8 = ObjectiveText3_loc7,
                         ObjectiveText4_loc8 = ObjectiveText4_loc7;

ALTER TABLE locales_npc_text
  ADD COLUMN Text0_0_loc8 longtext AFTER Text0_0_loc7,
  ADD COLUMN Text0_1_loc8 longtext AFTER Text0_1_loc7,
  ADD COLUMN Text1_0_loc8 longtext AFTER Text1_0_loc7,
  ADD COLUMN Text1_1_loc8 longtext AFTER Text1_1_loc7,
  ADD COLUMN Text2_0_loc8 longtext AFTER Text2_0_loc7,
  ADD COLUMN Text2_1_loc8 longtext AFTER Text2_1_loc7,
  ADD COLUMN Text3_0_loc8 longtext AFTER Text3_0_loc7,
  ADD COLUMN Text3_1_loc8 longtext AFTER Text3_1_loc7,
  ADD COLUMN Text4_0_loc8 longtext AFTER Text4_0_loc7,
  ADD COLUMN Text4_1_loc8 longtext AFTER Text4_1_loc7,
  ADD COLUMN Text5_0_loc8 longtext AFTER Text5_0_loc7,
  ADD COLUMN Text5_1_loc8 longtext AFTER Text5_1_loc7,
  ADD COLUMN Text6_0_loc8 longtext AFTER Text6_0_loc7,
  ADD COLUMN Text6_1_loc8 longtext AFTER Text6_1_loc7,
  ADD COLUMN Text7_0_loc8 longtext AFTER Text7_0_loc7,
  ADD COLUMN Text7_1_loc8 longtext AFTER Text7_1_loc7;

UPDATE locales_npc_text SET Text0_0_loc8 = Text0_0_loc7,
                            Text0_1_loc8 = Text0_1_loc7,
                            Text1_0_loc8 = Text1_0_loc7,
                            Text1_1_loc8 = Text1_1_loc7,
                            Text2_0_loc8 = Text2_0_loc7,
                            Text2_1_loc8 = Text2_1_loc7,
                            Text3_0_loc8 = Text3_0_loc7,
                            Text3_1_loc8 = Text3_1_loc7,
                            Text4_0_loc8 = Text4_0_loc7,
                            Text4_1_loc8 = Text4_1_loc7,
                            Text5_0_loc8 = Text5_0_loc7,
                            Text5_1_loc8 = Text5_1_loc7,
                            Text6_0_loc8 = Text6_0_loc7,
                            Text6_1_loc8 = Text6_1_loc7,
                            Text7_0_loc8 = Text7_0_loc7,
                            Text7_1_loc8 = Text7_1_loc7;

ALTER TABLE mangos_string
  ADD COLUMN content_loc8 text AFTER content_loc7;

UPDATE mangos_string SET content_loc8 = content_loc7;

