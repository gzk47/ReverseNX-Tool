#include "About_tab.hpp"

AboutTab::AboutTab() {		
	brls::Label* Label1 = new brls::Label(brls::LabelStyle::REGULAR, "ReverseNX-Tool " APP_VERSION, false);
	this->addView(Label1);

	brls::Label* Label2 = new brls::Label(brls::LabelStyle::MEDIUM, "ReverseNX和ReverseNX-Tool的研究与开发: MasaGratoR\n葡萄糖酸菜鱼 汉化\ngzk_47 补充汉化 发布", true);
	this->addView(Label2);
	
	brls::Label* Label3 = new brls::Label(brls::LabelStyle::DESCRIPTION, "版权所有 (C) 2020 MasaGratoR\n本程序是自由软件：您可以重新分发它和/或修改它，并遵守由自由软件基金会发布的GNU通用公共许可证第三版的条款。本程序的分发是希望它能发挥作用，但不提供任何担保，甚至没有适销性或特定用途适用性的暗示保证。有关详细信息，请参阅GNU通用公共许可证。您应该已经随程序收到了GNU通用公共许可证的副本。如果没有，请访问 https://www.gnu.org/licenses/", true);
	this->addView(Label3);
}

