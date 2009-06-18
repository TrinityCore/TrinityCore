delete from `command` where `name` IN ('senditems','sendmail');
insert into `command` (`name`, `security`, `help`) values
('senditems',3,'Syntax: .senditems #playername "#subject" "#text" itemid1[:count1] itemid2[:count2] ... itemidN[:countN]\r\n\r\nSend a mail to a player. Subject and mail text must be in "". If for itemid not provided related count values then expected 1, if count > max items in stack then items will be send in required amount stacks. All stacks amount in mail limited to 12.'),
('sendmail',1,'Syntax: .sendmail #playername "#subject" "#text"\r\n\r\nSend a mail to a player. Subject and mail text must be in "".');
 
