Directions = [[1,0],[1,1],[0,1],[-1,1],[-1,0],[-1,-1],[0,-1],[1,-1]]
Mark =        ['|', '\\', '-', '/',  '|',  '\\',  '-', '/']


class CrossWord
  attr_accessor :word, :place, :dir
  def initialize w
    @word=w
    @dir=0
    @place=nil
  end
  def unplaced?
    @place==nil
  end
end

class CharGrid
  def initialize cols,rows
    @w=cols
    @h=rows
    @g="."*(@w*@h)
    @ref_count = Array.new(@w*@h){0}
    @iterations = 0
  end

  #填充单词
  def fill words
    iterations = 0
    @words = words.map{|w| CrossWord.new(w)}
    words_todo = @words.select{|w|w.unplaced?}
    until words_todo.empty?
      words_todo.each{|cw| place cw }
      words_todo = @words.select{|w|w.unplaced?}.sort_by{rand}
      if (iterations+=1) %(@w+@h)==0
        #如果卡死，就移除一些单词
        puts "#{togo = words_todo.size} to go..."
        words_done = (@words-words_todo).sort_by{rand}
        (togo*2).times{|i| words_todo<< remove(words_done[i]) if words_done[i]}
      end
    end
    raise if (@g[0,1] == '.' or @g[@h-1,1] == '.' or @g[@h*@h-1,1] == '.' or @g[@h*(@h-1),1] == '.')  
    rescue
      @g="."*(@w*@h)
      @ref_count = Array.new(@w*@h){0}
      @iterations = 0
      retry
  end

  #返回随机填充的矩阵
  def to_s
    puz = @g.dup
    puz.size.times{|i|puz[i]=('a'..'z').to_a[rand(26)] if puz[i]==?.}
    sln=[]
    newwidth=(2*@w-1)
    @h.times{|r| sln<<puz[r*@w,@w].split('')*' '
    sln<<' '*newwidth
    }
    sln
  end

  #将字符串转换成数组
  def pack
    @g.sub!('.', ('a'..'z').to_a[rand(26)]) while @g['.']
     s=''
    @h.times{|r| s<<@g[r*@w,@w]<<"\n" }
    s
  end


  #生成解矩阵
  def solution
    sln=[]
    newwidth=(2*@w-1)
    @h.times{|r| sln<<@g[r*@w,@w].split('')*' '
    sln<<' '*newwidth
    }
    @words.each_with_index{|cw,i|
      next unless  cw.place
      pt = [cw.place/@w*2, cw.place % @w*2]
      (cw.word.size-1).times {
        pt[0]+=Directions[cw.dir][0]
        pt[1]+=Directions[cw.dir][1]
        sln[pt[0]][pt[1]] =
          case sln[pt[0]][pt[1]]
            when 32 then Mark[cw.dir]
            when ?-,?| then ?+
            else ?X
          end
        pt[0]+=Directions[cw.dir][0]
        pt[1]+=Directions[cw.dir][1]
      }
    }
    sln
  end

private
  def place cw
    @words.sort_by{rand}.each{|otherword|
      startpt = find_overlap(cw, otherword)
      return if test_place(cw, startpt)
    }
  end

  #检测cw是否和已有单词重叠
  #如果重叠返回坐标
  def find_overlap cw, testword
    return nil if testword.unplaced?
    if (offset = testword.word.index cw.word[0])
      startpt = testword.place
      offset.times{startpt=nextp(startpt,testword.dir)}
    else
      startpt = nil
    end
    startpt
  end

  # 随机生成一个起始点
  # 尝试从8个方向将cw放入矩阵
  def test_place cw, suggestion=nil
    dir=randDir
    start= suggestion || randStart(cw.word[0])
    8.times do
      pt = start
      good = true
      cw.word.each_byte{|chr|
        good = (@g[pt]==?. ||  @g[pt]==chr) && (pt=nextp(pt,dir))
        break unless good
      }
      return add(cw, start, dir) if good
      dir=(dir+1)%8
    end
    nil
  end

  #找规定方向上的下一个起始点
  def nextp pos, dir
    #不允许出界
    if (pos<@w && (3..5).include?(dir)) or
       (pos+@w >= @g.size && [0,1,7].include?(dir)) or
       (pos%@w == 0 && (5..7).include?(dir)) or
       (pos%@w+1 == @w && (1..4).include?(dir))
       return nil
    end
    pos+Directions[dir][0]*@w+Directions[dir][1]
  end

  #将单词按照给定方向和起始点写入矩阵
  def add cw, idx, dir
    puts "+#{cw.word}" if  $ShowProgress
    cw.dir = dir
    pt = cw.place = idx
    cw.word.each_byte{|chr|
      @g[pt]=chr
      @ref_count[pt]+=1
      pt=nextp(pt,dir)
    }
    return [idx,dir]
  end

  #从矩阵中移除单词
  def remove cw
    p "-#{cw.word}" if $ShowProgress
    pt = cw.place
    cw.word.each_byte{|chr|
      @g[pt]=?. if 0== (@ref_count[pt]-=1)
      pt=nextp(pt,cw.dir)
    }
    cw.place=nil
    cw
  end

  #随机找起始点
  def randStart matchChar
    start = rand(@w*@h)
    start= (start+1)%(@w*@h) until (@g[start]==?. || @g[start]==matchChar)
    start
  end

  def randDir
    rand(8)
  end
end


if __FILE__ == $0
  gridsize = ARGV[1].split('x').map{|v|v.to_i}
  g = CharGrid.new *gridsize
  words=File.open(ARGV[0],"r").read.split.sort_by{|s|s.length}.reverse
  puts "unsolvable!" or exit if (words[0].size>gridsize.max)

  g.fill words
  puts g.pack
  File.open("search.txt","w"){|f|f.puts g.to_s}
  File.open("solution.txt","w"){|f|f.puts g.solution}
end

