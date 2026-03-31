#include "FullOptionsFrame.hpp"

FullOptionsFrame::FullOptionsFrame() : AppletFrame(true, true) {		
	this->setTitle("ReverseNX-Tool");
	this->setIcon(BOREALIS_ASSET("icon.jpg"));
	
	brls::List* FullOptionsList = new brls::List();
	
	brls::Label* Warning2 = new brls::Label(brls::LabelStyle::DESCRIPTION, "对于32位游戏和黑名单中的游戏，修改将被忽略。", true);
	FullOptionsList->addView(Warning2);
	
	bool memorySafety2 = false;
	if (countGames > 56 && isAlbum) memorySafety2 = true;
	for (uint32_t i = 0; i < countGames; i++) {
		brls::SelectListItem* StatusItem2 = new brls::SelectListItem(titles.at(i).TitleName.c_str(), { "掌机模式", "底座模式", "系统默认" }, (unsigned)titles.at(i).ReverseNX);
			
		if (memorySafety2 == false) StatusItem2->setThumbnail(titles.at(i).icon, sizeof(titles.at(i).icon));
		double textLength = (double)titles.at(i).TitleName.size();
		if (textLength >= 43) StatusItem2->setTextSize((int)((22 / pow((textLength/43), 0.212))));
				
		StatusItem2->getValueSelectedEvent()->subscribe([i](size_t selection) {
			Flag changeFlag = (Flag)selection;
			setReverseNX(titles.at(i).TitleID, changeFlag, true);
			setReverseNX(titles.at(i).TitleID, changeFlag, false);
		});
				
		FullOptionsList->addView(StatusItem2);
	}
			
	FullOptionsList->registerAction("显示侧边栏", brls::Key::R, [] {
		brls::Application::popView();
		return true;
	});
			
	if (memorySafety2 && !memorySafety) brls::Application::notify("为了防止内存溢出，已禁用图标显示。");
	this->setContentView(FullOptionsList);
}
