#include "NavBar.h"

void NavBar::render(
	bool& showLogin,
	bool& showHostSettings,
	bool& showGamepads,
	bool& showChat,
	bool& showGuests,
	bool& showLog,
	bool& showAudio
)
{
	static ImVec2 iconSize = ImVec2(24, 24);
	static ImVec2 windowSize = ImVec2(24 + 3*8, 24*7 + 8*11);
	static ImVec2 zero = ImVec2(0, 0);
	static ImVec2 padding = ImVec2(8, 8);
	
	//ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, zero);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, padding);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_PopupRounding, 0);

	ImGui::Begin(
		"##NavBar", (bool*)0,
		ImGuiWindowFlags_NoDecoration |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoNav |
		ImGuiWindowFlags_NoBringToFrontOnFocus
	);
	ImGui::SetWindowSize(windowSize);
	ImGui::SetWindowPos(zero);
	
	if (ToggleIconButtonWidget::render(AppIcons::play, AppIcons::play, showHostSettings, iconSize))	showHostSettings = !showHostSettings;
	renderNavtooltip("Host settings", showHostSettings);

	if (ToggleIconButtonWidget::render(AppIcons::padOn, AppIcons::padOn, showGamepads, iconSize)) showGamepads = !showGamepads;
	renderNavtooltip("Gamepads", showGamepads);

	if (ToggleIconButtonWidget::render(AppIcons::chat, AppIcons::chat, showChat, iconSize))	showChat = !showChat;
	renderNavtooltip("Chat", showChat);

	if (ToggleIconButtonWidget::render(AppIcons::users, AppIcons::users, showGuests, iconSize))	showGuests = !showGuests;
	renderNavtooltip("Guests", showGuests);

	if (ToggleIconButtonWidget::render(AppIcons::log, AppIcons::log, showLog, iconSize)) showLog = !showLog;
	renderNavtooltip("Log", showLog);

	if (ToggleIconButtonWidget::render(AppIcons::speakersOn, AppIcons::speakersOn, showAudio, iconSize)) showAudio = !showAudio;
	renderNavtooltip("Audio", showAudio);

	if (IconButton::render(AppIcons::logoff, AppColors::primary, iconSize)) showLogin = !showLogin;
	TitleTooltipWidget::render("Log off", "Go back to log in screen.");

	ImGui::End();

	ImGui::PopStyleVar();
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();
	//ImGui::PopStyleVar();
}

void NavBar::renderNavtooltip(const char* title, bool& show)
{
	TitleTooltipWidget::render(title, show ? "Window is visible." : "Window is hidden.");
}
