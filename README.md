# 东方回映录

## 主要功能

* 显示 东方 Project 弹幕 STG 录像文件(*.rpy)中的录像信息。目前支持的作品如下：
	- 老正作(DX8)：
		+ 红魔乡[TH06], 妖妖梦[TH07], 永夜抄[TH08], 花映冢[TH09]
	- 正作(DX9):
		+ 风神录[TH10], 地灵殿[TH11], 星莲船[TH12], 神灵庙[TH13], 辉针城[TH14], 绀珠传[TH15]
	- 单关小品：
		+ 文花帖[TH95], 文花帖DS[TH125], 弹幕天邪鬼[TH143]
	- 多关小品：
		+ 妖精大战争[TH128]
	- 跑龙套：
		+ 黄昏酒场
* 支持读写录像注释。
	- **注：** 由于录像文件格式的限制，`红魔乡` 和 `妖妖梦` 的录像文件不支持添加注释。
* TH06-TH08 支持自动识别中文版录像。
	- TH09 以后的录像若要看中文版录像请事先在选项里选好编码，不然会乱码。
	- **注：** 如果不知道编码是神马，可以依次按键盘上的 `F1` ~ `F4`，有惊喜。
* 录像信息和录像注释均支持自动转码。
	- 这也需要在选项里事先设置好编码。
* 支持 设置/解除 与 .rpy 文件的关联。
* 部分作品的录像文件还支持显示每一关的信息，包括每一关开始时的Point 、Graze、樱点、夜点、通关分数等等（不同作品会显示不同信息）。
* 支持显示 TH09 的“大致”掉帧率，详见 `说明`。
* 还有复制、移动、删除录像的功能，主要用于方便自己整理录像。
* ...

## 更新历史

1.80(2015-08-29): 

* 增加：支持 `东方绀珠传` 正式版（体验版仅提供少量支持，只能显示摘要信息和注释以及编辑注释，不可显示各关数据和保存 raw 数据等等……反正也没什么人再玩了吧）。
* 增加：帮助文件 `thhylmenu.html`，详细说明程序中每个菜单项的作用。
* 增加：`菜单` -> `打开 ShanghaiAlice 文件夹` 。
* 增加：`关闭文件` 功能增加快捷键 `CTRL+W` 。
* 增加：主窗口上方增加 `自动完成` 复选框。该选项决定当手动在 `录像文件` 框中输入路径时是否允许自动完成。
* 增加：菜单项 `保存 raw 数据` 改名为 `保存原始数据`，并分成了2个子项目：`全部`和`自定义`，其中`自定义`可以自定义导出哪些关卡的数据，并将它们分别存在不同的文件中。
* 增加：`保存原始数据`->`全部`的标题栏上会显示 raw 数据大小和 rpy 文件大小。
* 增加：打开菜单和选择菜单项目时会在`录像信息`框里出现一些提示。
* 增加：`注释编辑`窗口的部分控件也加了点工具提示。
* 改进：本来在 Win7 下运行时，公共对话框（打开文件对话框、字体选择对话框等）会显示为 2000/XP 风格，现在则是 WIN7 风格。
* 改进：修正妖妖梦自带演示 REP 的版本号显示：`de.bug`->`debug` 。
* 改进：重新做了一下图标。
* 更改：原帮助文件 `thhyl.htm` 改名为 `thhyl.html`。
* 更改：现在第一次启动新版本时，PlayTime 和 SlowRateByFPS 会强制勾选，若不喜欢可以再去掉。
* 更改：`选项` -> `位于非标题栏也可拖动` 现在对所有窗口有效（“关于”窗口总是有效，不受该选项影响）
* BUG修正：改变主窗口大小时可能导致按钮文字显示不正确。
* BUG修正：无法显示神灵庙、辉针城正式版自带的演示REP的信息。
* BUG修正：修改注释若提示“部分字符无法转换”，可能引起内存泄露。
* 其他细节的修正。

## 编译

* 请参看 [!COMPILE.txt](!COMPILE.txt)

## 其他相关工具

* <https://www.zybuluo.com/wz520/note/15842>

