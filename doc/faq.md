# Frequently Asked Questions (FAQ)

## Why are there no times?
	The logfile obtained from an Observer doesn't contain any time information.
	Time is measured simply as the order in which the events are found in the logfile.
	Each recognized event progresses *time* by one unit.

## I think the player scores are wrong.
	The scores that you see during the game are not logged to the logfile.
	The score that `bzstats` reports are based on the kills, deaths and suicides
	it sees in the logfile. This accounts for the score over the period that is logged
	in the logfile.

## I think the team statistics are wrong.
	A player's team is only logged when joining the game.
	If the Observer that creates the logfile joins after a player did, `bzstats` will
	not be able to determine the team that player is on and will assign that
	player to the `Unknown` team.

## How can I contribute?
	You can contribute by
* Submitting ideas, bugreports and change requests.
* Creating nice default templates for reports and sending them to the development team.
* Promoting `bzstats` on forums and among your friends.
* Creating some nice graphics for the reports or the website.
* Joining the development team.
