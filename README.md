# flyingACE (王牌飞行员)
- **Difficult in Chinese? -> [English Version](#EnglishTitle)**
- 这是一个使用Cocos2d-x-3.X 开发的飞机大战游戏，实际版本为Cocos2d-x3.3
- 开发博客：<http://blog.csdn.net/yy19900806/article/category/2856067/>
- Demo演示：<http://v.youku.com/v_show/id_XODgzNDQwNDgw.html?f=23404712&o=0/>

---

## 开发环境 Dev Environment
- Linux OS (Ubuntu 14.04 LTS)
- Eclipse 4.4.1
- Cocos2d-x-3.3
- Android SDK 4.4.2 (API 19)
- Android NDK r10d
- gcc 4.8
- 在win32平台、linux平台、android平台、android虚拟机上测试通过

---

## 配置方法 Configure
```shell
cocos new -l cpp -p com.YOURNAME.flyingACE FlyingACE
mkdir gitsrc && cd gitsrc
git clone https://github.com/netbeen/flyingACE.git
```
- 然后用gitsrc中的Classes和Resources文件夹覆盖cocos新建的Classes和Resources文件夹，用Eclipse导入Android工程即可。

---

# 游戏界面 GUI
![GUI](http://ww2.sinaimg.cn/large/9e2d8c2djw1eoutbcwwzgg203o06jx6t.gif)


---

## 类功能分布 Files
- AppDelegate: 程序入口，初始化Director类的参数，场景构建，布景层挂载
- BulletLayer: 子弹层，用批量渲染技术加载子弹并维护子弹数据
- BulletUserData: 子弹数据
- ControlLayer: 游戏控制层，负责分数显示和暂停按钮
- EnemyLayer: 敌机层，加载敌机并维护敌机数据，检测敌机与子弹、敌机与我机及碰撞
- EnemyUserData: 敌机数据
- GameBackgroundLayer: 布景层，实现地图加载，循环滚动
- GameScene: 游戏主场景
- PlaneLayer: 飞机层，渲染飞机动画，响应用户滑屏操作
- PlaneUserData: 飞机数据
- ResultBackgroundLayer: 游戏结果场景中显示背景图片的层
- ResultButtonLayer: 游戏结果场景中显示并回调按钮事件的层
- ResultScene: 游戏结果场景
- SelectBackgroundLayer: 选择关卡界面背景层
- SelectButtonLayer: 选择关卡界面按钮层
- SelectScene: 选择关卡场景
- UFOLayer: 不明飞行物层，目前用于投放武器加强的buff和大招buff
- UFOUserData: 数据记录类，用于记录gift的类型
- WelcomeBackgroundLayer: 欢迎界面中的背景层
- WelcomeButtonLayer: 欢迎界面中的按钮回调函数
- WelcomeScene: 欢迎界面

---

# 鸣谢 Thanks
- 特别感谢TexturePacker的作者Andreas Löw为本次开发提供Pro版的序列号
- Thanks to Mr. Andreas Löw (the author of TexturePacker), for prividing the free key of TexturePacker pro.

---

# 联系方式 Contact Me
- Email: netbeen.cn@gmail.com
- QQ: 394062113

---

# 关键字 Keywords
- `cocos` `cocos2d` `cocos2dx` `cocos2dx3.0`

---

# <a name="EnglishTitle"/>flyingACE ( Document in English )
- This is a Cocos2dx game about aircraft fighting (using Cocos2dx binding C++). During this commit, the version of my Cocos2d is Cocos2d-x3.3.
- Development Blog <http://blog.csdn.net/yy19900806/article/category/2856067/>
- Video Demo: <http://v.youku.com/v_show/id_XODgzNDQwNDgw.html?f=23404712&o=0/>

---

## Dev Environment
- Linux OS (Ubuntu 14.04 LTS)
- Eclipse 4.4.1
- Cocos2d-x-3.3
- Android SDK 4.4.2 (API 19)
- Android NDK r10d
- gcc 4.8
- Tested under the win32, linux, android(both mobile and SDK).

---

## Configure
```shell
cocos new -l cpp -p com.YOURNAME.flyingACE FlyingACE
mkdir gitsrc && cd gitsrc
git clone https://github.com/netbeen/flyingACE.git
```
- And then, using folder named Classes and Resources to override the correspondence folder. Import with Eclipse for Android project.

---

# GUI
![GUI](http://ww2.sinaimg.cn/large/9e2d8c2djw1eoutbcwwzgg203o06jx6t.gif)

---

## Files
- AppDelegate: The init access of the program. Init the Direct and construct the Scenes.
- BulletLayer: Bullet Layer, using SpriteBatchNode to load bullets.
- BulletUserData: The data struct defined by myself. Recording the damage of each bullet.
- ControlLayer: Game Control Layer, it provide the function of displaying scrore and pause button.
- EnemyLayer: Loading the enemys, and also, prividing the interface of the crash detecting.
- EnemyUserData: The datastruct recording the some paramater of enemy plane, like HP and others. 
- GameBackgroundLayer: Background Layer, auto loading the background image and rolling.
- GameScene: The main scene of the game, contain the most object.
- PlaneLayer: Plane Layer, Interactive layer of the game.
- PlaneUserData: The datastruct recording the some paramater of enemy plane, like HP and others. 
- ResultBackgroundLayer: Show the background image in the result scene.
- ResultButtonLayer: Show the button in the result scene.
- ResultScene: Game result scene.
- SelectBackgroundLayer: To show Select Scene's background.
- SelectButtonLayer: To show Select Scene's button.
- SelectScene: Select Scene.
- UFOLayer: This layer is used for some  buffs, like enhance the bullet or get the big bomb.
- UFOUserData: The data structure recording the kind of UFO gift.
- WelcomeBackgroundLayer: Show the background image in the welcome scene.
- WelcomeButtonLayer: Show the button in the welcome scene.
- WelcomeScene: Welcome scene, the loading image.

---

# Thanks
- Thanks to Mr. Andreas Löw (the author of TexturePacker), for prividing the free key of TexturePacker pro.

---

# Contact Me
- Email: netbeen.cn@gmail.com
- QQ: 394062113

---

# Keywords
- `cocos` `cocos2d` `cocos2dx` `cocos2dx3.0`

---
