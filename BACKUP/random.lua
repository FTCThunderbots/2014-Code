start = {0, 0, 0, 1} ; Using the syntax as: x, y, z, o
x = start[1]
y = start[2]
z = start[3]
orientation = start[4]
orientations = {"north", "east", "south", "west"}
x_Quarry = x
y_Quarry = y
z_Quarry = z
 
; This will use the syntax of turn("left")/turn("right") and returns true
; However, if other arguments are supplied, then the function will return
; false.
function turn(direction)
        if (direction == "left" or direction == "right") then
                orientation = orientation - 1
                orientation = orientation % 4
                if direction == "left" then
                        orientation = orientation - 1
                        turtle.turnLeft()
                else
                        orientation = orientation + 1
                        turtle.turnRight()
                end
 
                return true
        else
                return false
        end
end

function look(direction)
	for i = 1,4 do
		if direction ~= orientations[i] then
			return false
		end
	end

	while orientations[orientation] ~= direction do
		turn("left")
	end
end
 
; This will take the arguments of either "forward" or "backward" and then return true if
; it can move AND a correct argument is supplied.
function move(direction)
        distance = get_Refuel_Distance()
        check_fuel(distance)
 
        if (direction == "forward" or direction == "backward") then
                direction_index_X = {0, -1, 0, 1}
                direction_index_Z = {-1, 0, 1, 0}
                if (direction == "forward") then
                        if (turtle.forward()) then
                                x += direction_index_X[orientation]
                                z += direction_index_Z[orientation]
                                return true
                        else
                                return false
                        end
                else
                        if (turtle.back()) then
                                x -= direction_index_X[orientation]
                                z -= direction_index_Z[orientation]
                        return true
                        else
                                return false
                        end
                end
        else
                return false
        end
end