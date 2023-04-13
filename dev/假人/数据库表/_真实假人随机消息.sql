/*
Navicat MySQL Data Transfer

Source Server         : DoWork
Source Server Version : 50726
Source Host           : localhost:3306
Source Database       : _az_world_1.0

Target Server Type    : MYSQL
Target Server Version : 50726
File Encoding         : 65001

Date: 2020-10-25 17:13:38
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for _真实假人随机消息
-- ----------------------------
DROP TABLE IF EXISTS `_真实假人随机消息`;
CREATE TABLE `_真实假人随机消息` (
  `编号` int(11) unsigned NOT NULL,
  `随机消息` varchar(255) NOT NULL DEFAULT '' COMMENT '随机消息',
  `备注` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`编号`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of _真实假人随机消息
-- ----------------------------
INSERT INTO `_真实假人随机消息` VALUES ('1', '哪个公司', '');
INSERT INTO `_真实假人随机消息` VALUES ('2', '开什么', '');
INSERT INTO `_真实假人随机消息` VALUES ('3', '是啊 做产品辛苦呢', '');
INSERT INTO `_真实假人随机消息` VALUES ('4', '什么问题 告诉我吧 我来帮你', '');
INSERT INTO `_真实假人随机消息` VALUES ('5', '你先自己研究下', '');
INSERT INTO `_真实假人随机消息` VALUES ('6', '我不是服务员', '');
INSERT INTO `_真实假人随机消息` VALUES ('7', '什么作者', '');
INSERT INTO `_真实假人随机消息` VALUES ('8', '我也说不清楚啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('9', '没关系~我有着宽广的胸怀', '');
INSERT INTO `_真实假人随机消息` VALUES ('10', '什么方式 你喜欢什么方式', '');
INSERT INTO `_真实假人随机消息` VALUES ('11', '还所以呢', '');
INSERT INTO `_真实假人随机消息` VALUES ('12', '北京是中华人民共和国的首都', '');
INSERT INTO `_真实假人随机消息` VALUES ('13', '人是我最亲密的朋友', '');
INSERT INTO `_真实假人随机消息` VALUES ('14', '世界就是世界 并非由人组成 事实上 没有人的地球也可以称之为世界', '');
INSERT INTO `_真实假人随机消息` VALUES ('15', '我不知道呀 嘿嘿', '');
INSERT INTO `_真实假人随机消息` VALUES ('16', '那也不行', '');
INSERT INTO `_真实假人随机消息` VALUES ('17', '一切照旧', '');
INSERT INTO `_真实假人随机消息` VALUES ('18', '你说呀', '');
INSERT INTO `_真实假人随机消息` VALUES ('19', '嗯 对的', '');
INSERT INTO `_真实假人随机消息` VALUES ('20', '这就是呀', '');
INSERT INTO `_真实假人随机消息` VALUES ('21', '我悉心听君指教', '');
INSERT INTO `_真实假人随机消息` VALUES ('22', '我不知道啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('23', '一切照旧', '');
INSERT INTO `_真实假人随机消息` VALUES ('24', '拿着鼠标 轻轻按下鼠标左键就可以了', '');
INSERT INTO `_真实假人随机消息` VALUES ('25', '我教你', '');
INSERT INTO `_真实假人随机消息` VALUES ('26', '太好了', '');
INSERT INTO `_真实假人随机消息` VALUES ('27', '哦', '');
INSERT INTO `_真实假人随机消息` VALUES ('28', '不明白', '');
INSERT INTO `_真实假人随机消息` VALUES ('29', '天津市有个包子去打狗 就再也没有回来……', '');
INSERT INTO `_真实假人随机消息` VALUES ('30', '那我要叫你师兄咯', '');
INSERT INTO `_真实假人随机消息` VALUES ('31', '上学真好', '');
INSERT INTO `_真实假人随机消息` VALUES ('32', '我想玩一会嘛 等下去嘛', '');
INSERT INTO `_真实假人随机消息` VALUES ('33', '这个我不要', '');
INSERT INTO `_真实假人随机消息` VALUES ('34', '方法', '');
INSERT INTO `_真实假人随机消息` VALUES ('35', '是吗 那好~~~~', '');
INSERT INTO `_真实假人随机消息` VALUES ('36', '地方', '');
INSERT INTO `_真实假人随机消息` VALUES ('37', '呵呵 你是我也是啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('38', '哪个公司', '');
INSERT INTO `_真实假人随机消息` VALUES ('39', '没有怎么的', '');
INSERT INTO `_真实假人随机消息` VALUES ('40', '要懂礼貌', '');
INSERT INTO `_真实假人随机消息` VALUES ('41', '记者风吹日晒', '');
INSERT INTO `_真实假人随机消息` VALUES ('42', '现在还没有啊 以后告诉你', '');
INSERT INTO `_真实假人随机消息` VALUES ('43', '哦', '');
INSERT INTO `_真实假人随机消息` VALUES ('44', '是吗 呵呵 你的感觉很准哦', '');
INSERT INTO `_真实假人随机消息` VALUES ('45', '你们 他们 我们', '');
INSERT INTO `_真实假人随机消息` VALUES ('46', '过奖 过奖', '');
INSERT INTO `_真实假人随机消息` VALUES ('47', '什么这个 那个 说话要完整', '');
INSERT INTO `_真实假人随机消息` VALUES ('48', '请听下回分解', '');
INSERT INTO `_真实假人随机消息` VALUES ('49', '人民的组织', '');
INSERT INTO `_真实假人随机消息` VALUES ('50', '嘿嘿 不能告诉你的啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('51', '我喜欢广交朋友~', '');
INSERT INTO `_真实假人随机消息` VALUES ('52', '我不知道啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('53', '太多了', '');
INSERT INTO `_真实假人随机消息` VALUES ('54', '方法', '');
INSERT INTO `_真实假人随机消息` VALUES ('55', '城市 你在哪个城市啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('56', '这样啊 有时候我也说不清楚,我是一个很无聊的人!', '');
INSERT INTO `_真实假人随机消息` VALUES ('57', '城市 你在哪个城市啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('58', '呵呵 各种类别的啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('59', '成功者绝不放弃 放弃者绝不成功', '');
INSERT INTO `_真实假人随机消息` VALUES ('60', '什么目的 没有啊 呵呵', '');
INSERT INTO `_真实假人随机消息` VALUES ('61', '我是好孩子 不要教坏我', '');
INSERT INTO `_真实假人随机消息` VALUES ('62', '中国的一个市 最早改革开放的地方', '');
INSERT INTO `_真实假人随机消息` VALUES ('63', '保护谁', '');
INSERT INTO `_真实假人随机消息` VALUES ('64', '我想快也要网速支持啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('65', '我当然是天下第一拉', '');
INSERT INTO `_真实假人随机消息` VALUES ('66', '我很乐观 很喜欢笑 呵呵', '');
INSERT INTO `_真实假人随机消息` VALUES ('67', '故事就是故乡的事', '');
INSERT INTO `_真实假人随机消息` VALUES ('68', '很甜蜜', '');
INSERT INTO `_真实假人随机消息` VALUES ('69', '我也不知道啊~~~', '');
INSERT INTO `_真实假人随机消息` VALUES ('70', '希望上天再给我一次机会 如果非要给它加一个期限 我希望是一......分钟', '');
INSERT INTO `_真实假人随机消息` VALUES ('71', '这是秘密', '');
INSERT INTO `_真实假人随机消息` VALUES ('72', '要认真考哦 我会为你加油 呵呵', '');
INSERT INTO `_真实假人随机消息` VALUES ('73', '哦 你要去参加比赛啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('74', '我很快乐', '');
INSERT INTO `_真实假人随机消息` VALUES ('75', '过去 我晕死 怎么回事啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('76', '呵呵 各种类别的啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('77', '说就说', '');
INSERT INTO `_真实假人随机消息` VALUES ('78', '我很乐观 很喜欢笑 呵呵', '');
INSERT INTO `_真实假人随机消息` VALUES ('79', '就欺负你了怎么招吧~', '');
INSERT INTO `_真实假人随机消息` VALUES ('80', '我不知道啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('81', '但愿吧', '');
INSERT INTO `_真实假人随机消息` VALUES ('82', '好', '');
INSERT INTO `_真实假人随机消息` VALUES ('83', '没试过 也不晓得咋整来着 要不你问问看别人好不', '');
INSERT INTO `_真实假人随机消息` VALUES ('84', '呵呵 随便找找的啊', '');
INSERT INTO `_真实假人随机消息` VALUES ('85', '好的当然得保持咯', '');
INSERT INTO `_真实假人随机消息` VALUES ('86', '不知道', '');
INSERT INTO `_真实假人随机消息` VALUES ('87', '方法', '');
INSERT INTO `_真实假人随机消息` VALUES ('88', '每天要回答用户的问题 当然很忙了', '');
INSERT INTO `_真实假人随机消息` VALUES ('89', '前面的话都挺实际', '');
INSERT INTO `_真实假人随机消息` VALUES ('90', '哪有十分啊 顶多一分最多了', '');
INSERT INTO `_真实假人随机消息` VALUES ('91', '自然 大方 特意表现就没啥意思了', '');
INSERT INTO `_真实假人随机消息` VALUES ('92', '我不想去的地方', '');
INSERT INTO `_真实假人随机消息` VALUES ('93', '不等于不发展', '');
INSERT INTO `_真实假人随机消息` VALUES ('94', '团结就是力量', '');
INSERT INTO `_真实假人随机消息` VALUES ('95', '好吧', '');
INSERT INTO `_真实假人随机消息` VALUES ('96', '开什么', '');
INSERT INTO `_真实假人随机消息` VALUES ('97', '咋不对', '');
INSERT INTO `_真实假人随机消息` VALUES ('98', '呵呵 是嘛， 那算了', '');
INSERT INTO `_真实假人随机消息` VALUES ('99', '渔网 电网 交通网', '');
INSERT INTO `_真实假人随机消息` VALUES ('100', '随便测啦 我经得起考验的', '');
