This README file is for devs, playtesters (who are technically literate),
or anyone interested in how the save files work.

Each `.json` file is a save file (`excluding save-template.json`)

"save-name" refers to the name of the save that the player gives it.
"description" is the description that the player gives it.
"author" is the user's name.
"last-edited" is the date that it was last edited.

"data" stores the actual data contained within the save file.
This includes the grid and the version the save was last edited in.

Although you could technically edit all other variables in the file
(if you wanted to), you _should not_ attempt to edit the grid variable.

The grid variable is stored in a very simple way.
It is an array of arrays, with each array in the array being a different
row. Example:
grid: 
[
  [0,1,2,3,4],
  [5,6,7,8,9],
  [10,11,12,14]
]