
difference() {
    difference() {
        cube([34,74,44], center = true);
        cube([30,70,40], center = true);
        translate([0,0,20]) {
            cube([5,200,5], center = true);
        };
        rotate([0,90,0]){
            cylinder(99, 8, 5, center = true, $fn=128);
        }; 
        translate([0,0,-22]) { holes(); };
    };
    


    translate([0,40,0]) {
        rotate([90,0,0]){
            cylinder(5, 5, 5, $fn=128);
        }; 
    }

};

module holes() {
    translate([0,-50,0]){

        for (i = [1:1:15]) { 
               translate([0,7*i,0]) { 
                   cylinder(2, 2, 2, $fn=128);
               };
            }
    }
}


