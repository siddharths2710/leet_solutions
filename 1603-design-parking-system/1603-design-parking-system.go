type ParkingSystem struct {
    big int
    medium int
    small int
}


func Constructor(big int, medium int, small int) ParkingSystem {
    obj := new(ParkingSystem)
    obj.big = big
    obj.medium = medium
    obj.small = small
    return *obj
}


func (this *ParkingSystem) AddCar(carType int) bool {
    switch carType {
        case 1: if this.big == 0 {
                return false
                } else { this.big-- }
        case 2: if this.medium == 0 { 
                return false 
                } else { this.medium-- }
        default: if this.small == 0 { 
                return false 
                } else { this.small-- }
    }
    return true
}


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */