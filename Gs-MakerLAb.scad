/*
Fabrício Gutierrez Saavedra - RM97631
Márcio Gastaldi - RM98811
Arthur Bessa Pian - RM99215
Davi Desenzi - RM550849
João Victor - RM551410
*/

$fn = 50;

angulo_abertura = 20;

haste_comprimento = 150;
haste_diametro = 8;

base_x = 20;
base_y = 20;
base_z = 15;

color("#FFD700") {

    translate([base_x/2, 0, 0])
    rotate([0, 90, 0])
    cylinder(h=haste_comprimento, d=haste_diametro, center=false);

    cube([base_x, base_y, base_z], center=true);

    translate([-base_x/2, base_y/2, 0])
    rotate([0, 0, -angulo_abertura])
    Garra();

    translate([-base_x/2, -base_y/2, 0])
    rotate([0, 0, angulo_abertura])
    mirror([0, 1, 0])
    Garra();
}

module Garra() {
    union() {
        translate([-15, 3, 0])
        cube([30, 6, base_z], center=true);

        translate([-32, -2, 0])
        rotate([0, 0, 45])
        cube([15, 6, base_z], center=true);
    }
}