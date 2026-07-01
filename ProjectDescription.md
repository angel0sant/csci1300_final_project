# CSCI 1300 Final Project

## Theme

Space/Astronomy themed game. 

## Goal

You are a barren planet tasked with making yourself habitable for life by collecting resources and managing your climate.

## Planned Classes

Planet: Manages the player's core stats (temperature, atmosphere, water levels, and energy).
Resource: Represents objects floating in space (ice comets, asteroids) that the planet can pull into its orbit.
Event: Handles random occurrences each turn (solar flares, alien probes) that impact the planet's stats.

## Planned Limited Resource & Plan for Handling Time

Limited Resource: "Cosmic Energy." The planet uses energy to pull resources into its orbit or trigger internal changes (like volcanic eruptions). 
Handling Time: The game will be turn-based, where each turn represents an "Epoch" (a million years). The player has a maximum number of Epochs to achieve habitability before their star burns out.

## Tradeoff System

Players must balance their stats using tradeoffs. For example, pulling an "Ice Comet" into your orbit will greatly increase your Water stat, but it will severely drop your Temperature stat. Alternatively, triggering a "Volcanic Eruption" will build your Atmosphere, but it raises your Temperature to dangerous levels. 

## Mapping Style

The map will be a 2D grid representing the orbital spacing around your star. The center will be the star, and different orbital rings will contain various resources (asteroids, comets) that spawn at different distances.

## Win/Lose Condition

Win Condition: The planet successfully reaches the required thresholds for Water, Temperature, and Atmosphere to sustain life before time (Epochs) runs out.
Lose Condition: The planet's energy reaches zero, time runs out, or a stat reaches a critical failure point (temperature becomes too hot, turning the planet into a wasteland).

## Extra Credit

(TBA)
