def simple_sum
    two = 2
    three = 3
    sum = 2 + 3
    puts(sum)
end


def simple_area
    radius = 5.0

    # Error: Dynamic assignment
    # Math.PI_SM = 3.14
    
    pi = 3.14
    r_sq = radius * radius

    area = pi * r_sq
    puts(area)
end

module Area
    class Circle
        def calculate
            # ...
        end
    end
end


