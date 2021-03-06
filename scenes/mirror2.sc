camera {
	pos(0,0,-5)
	rotation(0,0,0)
}

object {
	type(sphere)
	pos(0, 15, 55)
	radius(8)
	color(125, 137, 228)
	mirror(80)
}

object {
	type(sphere)
	pos(15, 0, 55)
	radius(8)
	color(125, 228, 137)
	mirror(80)
}

object {
	type(sphere)
	pos(-15, 0, 55)
	radius(8)
	color(228, 137, 125)
	mirror(80)
}

object {
	type(plane)
	pos(0, 25, 0)
	rotation(90, 0, 0)
	color(255, 255, 255)
}

object{
	type(plane)
	pos(0, -25, 0)
	rotation(90, 0, 0)
	color(255, 255, 255)
	checkered
}

object{
	type(plane)
	pos(0, 0, 100)
	rotation(0, 0, 0)
	color(255, 255, 255)
	mirror(80)
}

object{
	type(plane)
	pos(-40, 0, 0)
	rotation(0, 90, 0)
	color(255, 255, 255)
}

object{
	type(plane)
	pos(40, 0, 0)
	rotation(0, 90, 0)
	color(255, 255, 255)
}

object{
	type(plane)
	pos(0, 0, -20)
	rotation(0, 0, 0)
	color(255, 255, 255)
}

light{
	pos(0,0,-5)
}
light{
	pos(0,0,90)
}
