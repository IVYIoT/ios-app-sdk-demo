//
//  HomeController.m
//  IvySdk
//
//  Created by JackChan on 25/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import "HomeController.h"
#import "LiveController.h"
#import "WiFiConfiguration.h"
#import "Masonry.h"
#import "IvyCamera.h"
#import "UIImage+IvySdk.h"
#import "Constants.h"

static NSString * const kCellID = @"CellID";

@interface HomeController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) NSArray<IvyCamera *> *dataSource;

@property (nonatomic, strong) UITableView *tableView;

@end

@implementation HomeController

#pragma mark - Lifecycle
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAdd target:self action:@selector(addDevice)];
    
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kCellID];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:kCellID];
        cell.backgroundColor = RGBCOLOR(250, 250, 250);
    }
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    
    IvyCamera *obj = self.dataSource[indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"UID:%@", obj.deviceUID];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Username:%@\tPassword:%@", obj.username, obj.password];
    
    BOOL online = (obj.handleState == IVYIO_HANDLE_STATE_ONLINE);
    cell.backgroundColor = online ? RGBCOLOR(118, 214, 114) : RGBCOLOR(250, 250, 250);
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    IvyCamera *obj = self.dataSource[indexPath.row];
    LiveController *vc = [[LiveController alloc] initWithIvyCamera:obj];
    [vc preload];
    [self.navigationController pushViewController:vc animated:YES];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 64.f;
}

#pragma mark - Event Response
- (void)addDevice {
    WiFiConfiguration *vc = [WiFiConfiguration new];
    [self.navigationController pushViewController:vc animated:YES];
}

#pragma mark - Getter && Setter
- (NSArray *)dataSource {
    if (!_dataSource) {
        NSMutableArray *mutableArray = [NSMutableArray new];
        {
            NSString *deviceUID = kDeviceUID;
            NSString *username = kUsername;
            NSString *password = kPassword;
            IvyCamera *obj = [[IvyCamera alloc] initWithDeviceUID:deviceUID username:username password:password];
            
            NSLog(@"... loginCamera Begin");
            __weak typeof(self) weakSelf = self;
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [obj loginCamera:^(IVYIO_HANDLE_STATE handleState, IVYIO_RESULT cmdResult) {
                    [weakSelf.tableView reloadData];
                    NSLog(@"... loginCamera End handleState:%@ cmdResult:%@", @(handleState), @(cmdResult));
                }]; // 登陆设备
            });
            [mutableArray addObject:obj];
        }
        
        _dataSource = [mutableArray copy];
    }
    return _dataSource;
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleGrouped];
        _tableView.backgroundColor = [UIColor clearColor];
        _tableView.dataSource = self;
        _tableView.delegate = self;
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
    }
    return _tableView;
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
