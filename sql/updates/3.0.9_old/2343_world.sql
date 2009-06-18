DELETE FROM `command` WHERE `name` LIKE "ahbotoption %";
DELETE FROM `command` WHERE `name` LIKE "ahbotoptions %";
INSERT INTO `command`(`name`,`security`,`help`) VALUES 
('ahbotoptions ahexpire', '3', '.Syntax: .ahbotoptions ahexpire $ahMapID Expire all auctions started by AHbot.'),
('ahbotoptions minitems', '3', '.Syntax: .ahbotoptions minitems $ahMapID $parameter Set minimum number of items to be sold in the auctionhouse. If value is 0 then minitems=maxitems. If minitems>maxitems then it will be set equal to maxitems.'),
('ahbotoptions maxitems', '3', '.Syntax: .ahbotoptions maxitems $ahMapID $parameter Set maximum number of items to be sold in the auctionhouse.'),
('ahbotoptions mintime', '3', '.Syntax: .ahbotoptions mintime $ahMapID $parameter Set minimum number of hours for the items\' auction.'),
('ahbotoptions maxtime', '3', '.Syntax: .ahbotoptions maxtime $ahMapID $parameter Set maximum number of hours for the items\' auction.'),
('ahbotoptions percentages', '3', '.Syntax: .ahbotoptions percentages $ahMapID $greytrade $whitetrade $greentrade $bluetrade $purpletrade $orangetrade $yellowtrade $greyitem $whiteitem $greenitem $blueitem $purpleitem $orangeitem $yellowitem Set percentages for item types to be sold. Percentages must add up to 100, no higher. If percentage is set to 0 then item type will be disabled.'),
('ahbotoptions minprice', '3', '.Syntax: .ahbotoptions minprice $ahMapID $color $price Set rate for minimum selling price for item. 1=100%, 1.5=150%...'),
('ahbotoptions maxprice', '3', '.Syntax: .ahbotoptions maxprice $ahMapID $color $price Set rate for maximum selling price for item. 1=100%, 1.5=150%...'),
('ahbotoptions minbidprice', '3', '.Syntax: .ahbotoptions minbidprice $ahMapID $color $price Set minimum possible bid made considering buyoutprice. 30=30% of buyout price, 40%=40%...'),
('ahbotoptions maxbidprice', '3', '.Syntax: .ahbotoptions maxbidprice $ahMapID $color $price Set maximum possible bid made considering buyoutprice. 70=70% of buyout price, 80%=80%...'),
('ahbotoptions maxstack', '3', '.Syntax: .ahbotoptions maxstack $ahMapID $color $value Set maximum stacks for single item in auction. if set to 0 then item_template.stackable value will be considered $color: grey, white, green, blue, purple, orange, yellow.'),
('ahbotoptions buyerprice', '3', '.Syntax: .ahbotoptions buyerprice $ahMapID $color $value Set rate for which Ahbot will be allowed to buy an item. 1=item_template.sellprice, 2=2*item_template.sellprice... $color: grey, white, green, blue, purple, orange, yellow.'),
('ahbotoptions bidinterval', '3', '.Syntax: .ahbotoptions bidinterval $ahMapID $parameter Set number of minutes between bids'),
('ahbotoptions bidsperinterval', '3', '.Syntax: .ahbotoptions bidsperinterval $ahMapID $parameter Set number of bids to be made per cycle.');
