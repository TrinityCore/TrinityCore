DELETE FROM `command` WHERE `name` LIKE "ahbotoption %";
INSERT INTO `command`(`name`,`security`,`help`) VALUES
('ahbotoption ahexpire', '3', '.Syntax: .ahbotoption ahexpire $ahMapID Expire all auctions started by AHbot.'),
('ahbotoption minitems', '3', '.Syntax: .ahbotoption minitems $ahMapID $parameter Set minimum number of items to be sold in the auctionhouse. If value is 0 then minitems=maxitems. If minitems>maxitems then it will be set equal to maxitems.'),
('ahbotoption maxitems', '3', '.Syntax: .ahbotoption maxitems $ahMapID $parameter Set maximum number of items to be sold in the auctionhouse.'),
('ahbotoption mintime', '3', '.Syntax: .ahbotoption mintime $ahMapID $parameter Set minimum number of hours for the items\' auction.'),
('ahbotoption maxtime', '3', '.Syntax: .ahbotoption maxtime $ahMapID $parameter Set maximum number of hours for the items\' auction.'),
('ahbotoption percentages', '3', '.Syntax: .ahbotoption percentages $ahMapID $greytrade $whitetrade $greentrade $bluetrade $purpletrade $orangetrade $yellowtrade $greyitem $whiteitem $greenitem $blueitem $purpleitem $orangeitem $yellowitem Set percentages for item types to be sold. Percentages must add up to 100, no higher. If percentage is set to 0 then item type will be disabled.'),
('ahbotoption minprice', '3', '.Syntax: .ahbotoption minprice $ahMapID $color $price Set rate for minimum selling price for item. 1=100%, 1.5=150%...'),
('ahbotoption maxprice', '3', '.Syntax: .ahbotoption maxprice $ahMapID $color $price Set rate for maximum selling price for item. 1=100%, 1.5=150%...'),
('ahbotoption minbidprice', '3', '.Syntax: .ahbotoption minbidprice $ahMapID $color $price Set minimum possible bid made considering buyoutprice. 30=30% of buyout price, 40%=40%...'),
('ahbotoption maxbidprice', '3', '.Syntax: .ahbotoption maxbidprice $ahMapID $color $price Set maximum possible bid made considering buyoutprice. 70=70% of buyout price, 80%=80%...'),
('ahbotoption maxstack', '3', '.Syntax: .ahbotoption maxstack $ahMapID $color $value Set maximum stacks for single item in auction. if set to 0 then item_template.stackable value will be considered $color: grey, white, green, blue, purple, orange, yellow.'),
('ahbotoption buyerprice', '3', '.Syntax: .ahbotoption buyerprice $ahMapID $color $value Set rate for which Ahbot will be allowed to buy an item. 1=item_template.sellprice, 2=2*item_template.sellprice... $color: grey, white, green, blue, purple, orange, yellow.'),
('ahbotoption bidinterval', '3', '.Syntax: .ahbotoption bidinterval $ahMapID $parameter Set number of minutes between bids'),
('ahbotoption bidsperinterval', '3', '.Syntax: .ahbotoption bidsperinterval $ahMapID $parameter Set number of bids to be made per cycle.');
